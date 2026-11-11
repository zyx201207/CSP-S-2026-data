#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
using ll=long long;
ll dis[N];
int n;
ll m;
int que[N],l,r;
int cnt[N];
ll a[N];
void solve(){
	scanf("%d%lld",&n,&m);
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(dis,0x3f,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		dis[i]=0;
		que[1]=i;
		cnt[i]=1;
		l=1,r=1;
		for(int j=i+1;j<=n;j++){
			while(l<=r&&a[j]-a[que[l]]>m)l++;
			if(l>r)break;
			int tmp=0;
			for(int k=l;k<=r&&tmp<=2;k++){
				if(dis[que[k]]==dis[que[l]])tmp+=cnt[que[k]];
			}
			if(tmp==2)ans++;
			cnt[j]=tmp;
			dis[j]=dis[que[l]]+1;
			que[++r]=j;
		}
	}
//	cout<<"in\n";
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	scanf("%d%d",&c,&t);
	while(t--){
		solve();
	}
	return 0;
}  
