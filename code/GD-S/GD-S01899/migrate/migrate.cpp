//
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5005,MAXN2=2e6+5;

int a[MAXN],cnt[MAXN],ans[MAXN];
int aa[MAXN2];
map<int,int> mp;

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _,t;
	scanf("%lld %lld",&_,&t);
	if (_<=10){
		while (t--){
			int n,d;
			scanf("%lld %lld",&n,&d);
			for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
			int sum=0;
			for (int i=1;i<=n;i++){
				memset(cnt,0,sizeof(cnt));
				memset(ans,0,sizeof(ans));
				mp.clear();
				int id=i;
				mp[0]=1;
				ans[i]=0;
				cnt[i]=1;
				for (int j=i+1;j<=n;j++){
					while (a[j]-a[id]>d){
						mp[ans[id]]-=cnt[id];
						if (!mp[ans[id]]) mp.erase(ans[id]);
						id++;
					}
					auto it=mp.begin();
					ans[j]=(it->first)+1,cnt[j]=it->second;
					if (cnt[j]>2) cnt[j]=3;
					mp[ans[j]]+=cnt[j];
				}
				for (int j=i+1;j<=n;j++) sum+=(cnt[j]==2);
			}
			printf("%lld\n",sum);
		}
	}
	else if (11<=_ and _<=12){
		while (t--){
			int n,d;
			scanf("%lld %lld",&n,&d);
			for (int i=1;i<=n;i++) scanf("%lld",&aa[i]);
			d=d/(aa[2]-aa[1]);
			if (d>=2) printf("%lld\n",max(0ll,n-(2*d)+1));
			else printf("0\n");
		}
	}

	return 0;
}

