#include <bits/stdc++.h>
#define ll long long
#define inf 0x3fffffff
using namespace std;
int c,t,n,flag1=1,flag2,ho[1000005],dis[1000005];
ll a[1000006];
unsigned ll d,ans;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		ans=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> a[i],dis[i]=0;
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) flag1=0;
		}
		for(int i=1;i<=n;i++){
			if(a[i]-a[1]<=d&&a[n]-a[i]<=d) flag2=i;
		}
		if(flag1){
			unsigned ll gc=a[2]-a[1],jl;
			if(gc/d>=1){
				cout << 0 << endl;
			} else {
				jl=d/gc;
				if((jl>=n/2&&n%2==1)||(jl>n/2&&n%2==0)) cout << 0 << endl;
				else cout << n-(2*jl-1) << endl;
			}
		}
		int l=1,r=2;
		while(l<=r&&r<=n){
			if(a[r]-a[l]>d) ho[l]=r-1,l++;
			else r++;
		}
		for(int i=1;i<flag2;i++){
			if(ho[i]!=flag2&&ho[ho[i]]>flag2){
				dis[ho[ho[i]]+1]--;
				dis[flag2]++;
			}
		}
		for(int i=1;i<=n;i++) dis[i]+=dis[i-1];
		for(int i=1;i<=n;i++){
			if(i==flag2) continue;
			if(dis[i]==1) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
