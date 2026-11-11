#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mem(a,b) memset(a,b,sizeof(a))
#define For(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
#define Gor(i,a,b) for (int (i)=(a);(i)>=(b);(i)--)
using namespace std;
const int N=2e6+10;
int C,T,n,d,a[N],pre[N],nxt[N],f[N],s[N],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	IOS
	cin >> C >> T;
	while (T--){
		cin >> n >> d;
		For(i,1,n){
			cin >> a[i];
		}
		For(i,1,n){
			pre[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
			nxt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		}
		ans=0;
		For(i,1,n-1){
			f[i]=0;
			For(j,0,n) s[j]=0;
			s[i]=1;
			s[i-1]=0;
			int r=i;
			For(j,i+1,n){
				if (pre[j]==j) break;
				int k=max(i,pre[j]);
				f[j]=f[k]+1;
				while (r<j&&f[r+1]+1==f[j]) r++;
				ans+=(s[r]-s[k-1]==2);
				s[j]=s[j-1]+s[r]-s[k-1];
			}
		}
		cout << ans << '\n';
	}
}
