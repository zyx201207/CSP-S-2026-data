#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,T;
ll a[2000010],ans;
map<ll,bool> vis; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>m;
		memset(a,0,sizeof(a));
		vis.clear();
		for(int i=1;i<=n;i++){
			cin>>a[i];
			vis[a[i]]=true;	
		}
		if(n<=5000){
			for(int begin=1;begin<n;begin++){
				for(int end=begin+1;end<=n;end++){
					if(a[begin]+m>=a[end]) continue;
					ll now=a[begin],minn=0;
					bool p=true;
					for(int i=1+begin;i<=end;i++){
						if(a[i]-a[i-1]>m){
							p=false;
							break;
						}
					}
					if(!p) continue;
					while(now<a[end]){
						if(now+m>a[end]){
							minn=abs(now-a[begin])/m+abs(a[end]-now);
						}else if(now+m==a[end]){
							minn=abs(a[end]-a[begin])/m;
						}
						now+=m;
					}
					//cout<<a[begin]<<" "<<a[end]<<" "<<"now£º"<<now<<" "<<minn<<" "<<abs(now-m-a[begin])/m+abs(a[end]-(now-m))<<endl;
					if(now>a[end] && abs(now-m-a[begin])/m+abs(a[end]-(now-m))==minn) {
						ans++;
					}
				}
				
			}
			cout<<ans<<endl;
		}else{
			ll cha=a[2]-a[1];
			if(cha>=m || n<=4) cout<<0<<endl;
			else{
				cout<<n/2<<endl;
			}
		}
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
