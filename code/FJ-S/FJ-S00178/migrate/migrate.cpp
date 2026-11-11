#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e6 +5;
ll c,T,n,d,a[N],qwq[N],cnt,fl[N],f[N],ans,lsl[N],lsr[N],sum[N],suf[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)qwq[i]=fl[i]=lsl[i]=lsr[i]=f[i]=sum[i]=suf[i]=0;
		for(int i=1;i<=n-3;i++){
			if(a[i+3]-a[i]>d&&a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d)qwq[i]=1;
		}
		suf[n]=n;
		for(int i=n-1;i>=1;i--){
			if(a[i+1]-a[i]>d)suf[i]=i;
			else suf[i]=suf[i+1];
		}
		for(int i=1;i<=n-3;i++){
			if(a[i+3]-a[i]<=d)fl[i]=1;
		}
		//for(int i=1;i<=n;i++)cout<<qwq[i]<<" ";
		for(int i=1,j=1;i<=n;i++){
			while(j<=n&&a[j]-a[i]<=d)j++;
			j--;
			if(!lsl[j])lsl[j]=i;
			lsr[j]=i;
		}
		ll lst=1;
		for(int i=1;i<=n-3;i++){
			if(fl[i]||a[i]-a[i-1]>d){
				if(fl[i])lst=i+1;
				else lst=i;
				continue;
			}
			int x=max(lsl[i],lst+1),y=lsr[i];
			f[i]=max(0ll,sum[y]-sum[x-1])+1;
			if(qwq[i])ans+=f[i]*max(0ll,suf[i]-2-i);
			sum[i]=sum[i-1]+f[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//白鸟过河滩~，回忆会一去不回返~，一去不回返~，风起水起难靠岸~ 
//白鸟白鸟不要回头望~，你要替我飞去那地方~，一去那地方~，那是你我共同故乡~ 

//不是最后十分钟才发现假了，改不了了啊 
