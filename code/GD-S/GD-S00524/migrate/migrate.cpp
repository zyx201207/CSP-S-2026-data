#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long a[2000010];
long long n,d;
long long ans;
long long sum;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int u=1;u<n;u++){
			int flag=1;
			for(int v=u+2;v<=n&&flag;v++){
				if(a[v]-a[u]<=d){
					continue;
				}
				for(int i=u+1;i<=v;i++){
					if(a[i]-a[i-1]>d){
						flag=0;
						break;
					}
				}
				if(flag==0){
					break;
				}
				sum=0;
				for(int now=u+2;now<=v;now++){
					if(sum>2){
						flag=0;
						break;
					}
					if(a[now]-a[now-2]<=d){
						sum++;
					}
				}
				if(sum==2){
					ans++;
				}
			}
		}
		if(t==0){
			cout<<ans;
		}else{
			cout<<ans<<"\n";
		}
	}
}
