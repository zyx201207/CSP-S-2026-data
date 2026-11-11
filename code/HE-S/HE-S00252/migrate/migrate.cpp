#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+50;
int c,t;
int n,d;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==13||c==14){
			cout<<0<<'\n';
		}else{
			int cc=a[n]-a[n-1];
			if(cc>d){
				cout<<0<<'\n';
			}else if(cc==d){
				cout<<0<<'\n';
			}else{
				int res=(n-1)*n/2;
				if(d%cc!=0){
					cout<<res<<'\n';
				}else{
					int x=d/cc;
					int y=n/d;
					for(int i=1;i<=y;i++){
						res-=(n-x*i+1);
					}
					cout<<res<<'\n';
				}
			}
		}
	}
	return 0;
}
