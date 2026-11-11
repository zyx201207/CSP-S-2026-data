#include<bits/stdc++.h>
using namespace std;
long long n,m,q,w;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	while(m--){
		cin>>q>>w;
		long long a[200005],ans=0;
		for(long long i=1;i<=q;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+q);
		for(long long i=1;i<=q-2;i++){
			for(long long j=i+3;j<=q;j++){
				int o,p;
				if(a[i+1]-a[i]>w) break;
				if(a[j]-a[i]<=w) break;
				for(int k=i+1;k<j;k++){
					if(a[k]-a[i]>w){
						o=i-1;
					}else if(a[k]-a[i]==w){
						o=i;
					}
				}
				for(int k=j-1;k>i;k--){
					if(a[j]-a[k]<=w){
						p=i;
					}
				}
				if(a[j]-a[o]<=w && a[p]-a[i]<=w && o!=p){
					ans++;
				}
			}
		}
		cout<<ans+1<<endl;
	}
	return 0;
}
