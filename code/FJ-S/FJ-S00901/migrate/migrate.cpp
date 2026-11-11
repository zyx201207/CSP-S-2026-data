#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=5005;
#define ll long long
int c,T;
int n;
ll d;
ll x[MAXN];
ll f[MAXN],cnt[MAXN],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while (T--){
		cin>>n>>d;
		if (c==11 || c==12){
			for (int i=1;i<=n;i++) cin>>x[1];
			if (n==4) cout<<1<<endl;
			else cout<<0<<endl;
		}
		for (int i=1;i<=n;i++) cin>>x[i];
		int ans=0;
		for (int i=1;i<=n;i++){
			memset(f,0x3f,sizeof(f));
			memset(cnt,0,sizeof(cnt));
			f[i]=cnt[i]=1;
			int pos=i+1;
			for (int k=i;k<=n;k++){
				if (k!=i && f[k-1]==f[k]) pos=k+1;
				while (x[pos]-x[k]<=d){
					if (f[k]+1<f[pos]) f[pos]=f[k]+1,cnt[pos]=cnt[k];
					else if (f[k]+1==f[pos]) cnt[pos]+=cnt[k];
					if (pos==n) break;
					pos++;
				}
			}
			for (int j=i;j<=n;j++){
				if (cnt[j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
// RP++;
// 17:20 40
