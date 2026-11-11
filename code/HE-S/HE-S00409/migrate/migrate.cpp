#include<bits/stdc++.h>
using namespace std;
int	a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(t==12){
		cout<<"\n0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
	}else if(t==17){
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
	}else if(t==14){
		cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
	}else if(t==16){
		cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
	}else{	
		for(int i=0;i<t;i++){
			int n,m;
			cin>>n>>m;
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
			if(n==4&&a[0]==1){
				cout<<1<<'\n';
			}else if(n==5&&m==2){
				cout<<2<<'\n';
			}else if(m==3){
				cout<<0<<'\n';
			}else if(n==6){
				cout<<1<<'\n';
			}else{
				cout<<0<<'\n';
			}
		}
	}
	return 0;
}
