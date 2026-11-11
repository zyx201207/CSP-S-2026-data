#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,k;
ll dis[5005][5005];
ll i,j;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ll sum=k,cnt=0;
		for(i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
			if(u==1||v==n){
				sum*=k;
				cnt++;
			}
		}
		cout<<(sum/(n+k)+cnt+1)/4<<endl;
	}
	return 0;
}
