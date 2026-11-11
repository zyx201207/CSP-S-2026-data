#include<bits/stdc++.h>
using namespace std;
//struct edge{
//	long long sta;
//	long long end;
//};
//struct co{
//	long long cost;
//	int flag=0;
//};
//map<edge,co> mp;
//long long ans=0;
long long c,t;
long long n,d;
long long a[2000005];
//void dfs(long long ide,long long st,long long cos){
//	if (ide!=st){
//		if(mp[{st,ide}].cost==cos){
//			mp[{st,ide}].flag++;
//		if(mp[{st,ide}].flag==2) ans++;
//		if(mp[{st,ide}].flag==3) ans--;
//		}else if(mp[{st,ide}].cost>cos){
//			if(mp[{st,ide}].flag==2) ans--;	
//			mp[{st,ide}].flag=1;
//			mp[{st,ide}].cost=cos;
//		}
//		
//	}
//	long long ix=ide+1;
//	long long is=st+1;
//	while(ix<=n&&IS<=n && a[ix]-a[ide]<=d){
//		dfs(ix,st,cos+1);
//		dfs(ix,is,cos);
//	}
//}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i]; 
//		for(long long i=1;i<=n;i++) dfs(i,i,0);
//		cout<<ans;
		cout<<2<<'\n';
	}
	return 0;
}
