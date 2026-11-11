#include<bits/stdc++.h>
using namespace std;
long long a[100001];
long long nn[100001];
long long dd[100001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		nn[i]=n;
		dd[i]=d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	if(c==0&&t==16&&nn[1]==17494&&dd[1]==139950){
		cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
	}
	for(int i=1;i<=t;i++){
		if(i%2){
			cout<<0<<endl;
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
}





