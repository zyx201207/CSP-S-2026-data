#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,sum,ans,cnt,maxx;
ll a[500005];
int c[500005]; 
map<int,int>mp;
ll N=-1000000000002;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
		if(mp[a[i]]>1){
			a[i]=N;
			cnt++;
		}
		maxx=max(maxx,1ll*mp[a[i]]);	
	}
	sort(a+1,a+n+1);
	cnt+=1;
	for(int i=cnt+1;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	ans+=mp[a[cnt]];
	for(int i=1+cnt;i<=n;i++){
		ll to=m;
		m-=c[i]*ans;
		ans+=mp[a[i]];
		if(m<0){
//			cout<<ans<<" "<<m<<" "<<to<<" "<<mp[a[i]]<<" ";
			ans-=mp[a[i]];
//			ans+=to/c[i];
//			int k=i;
//			m=to;
//			while(m>0){
//				if(m-mp[a[k]]*c[k]>=0){
//					m-=m-mp[a[k]]*c[k];
//					ans+=mp[a[k]];
//					k--;
//				}else{
//					ans+=m/c[k];
//					break;
//				}
//			}
			break;
		} 
	}
	ans=max(ans,maxx);
	printf("%lld",ans);
	return 0;
}
//315275
//172.16.12.5
