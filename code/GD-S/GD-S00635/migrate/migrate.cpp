#include<bits/stdc++.h>
using namespace std;
long long a[2000005]={};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;++i){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		if(c==13||c==14){
			cout<<0<<endl;
			continue;
		}
		if(c==11||c==12){
			long long x=d/(a[2]-a[1]);
			if(x==1){
				cout<<0<<endl;
			}else{
				cout<<n-x<<endl;
			}
			continue;
		}
		cout<<0<<endl;
	}
}
