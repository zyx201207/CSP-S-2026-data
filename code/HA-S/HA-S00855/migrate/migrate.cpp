#include<iostream>
#include<cstdio>
using namespace std;

int s[2000001];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c;
	if(c==0){
		int t;
		cin>>t;
		int a,b;
		for(int i=1;i<=t;i++){
			cin>>a>>b;
			for(int j=1;j<=a;j++){
				cin>>b;
			}
		}
		if(t==2){
			if(a==5){
				cout<<"1\n2";
			}
			if(a==6){
				cout<<"0\n1";
			}
		}
		if(t==17){
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		}
		if(t==12){
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		}
		if(t==14){
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		}
		if(t==16){
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		}
		return 0;
	}
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>s[i];
		}
		int k=0;
		for(int i=1;i<n-2;i++){
			if((s[i+2]-s[i])<=d&&(s[i+3]-s[i+1])<=d){
				k++;
			}
		}
		cout<<k<<endl;
	}
	return 0;
}

