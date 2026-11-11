#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int c,t,n,pos,pos2,pos3;
long long d,a[N],x,ans;
int main(){
 	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;ans = 0;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i<=n;i++){
			int flag=0,now = upper_bound(a+1,a+1+n,a[i]+d) - (a+1);
			pos = pos2 = pos3 = 0;
			while(now<n){
				int pos = upper_bound(a+1,a+1+n,a[now]+d) - (a+1);
				if(pos==now) break;
				if(now>1) pos2 = upper_bound(a+1,a+1+n,a[now-1]+d) - (a+1);
				if(now>2) pos3 = upper_bound(a+1,a+1+n,a[now-2]+d) - (a+1);
				if(pos2&&flag&&pos==pos2) break;
				if(pos2&&pos3&&pos==pos2&&pos2==pos3) break;
				if(flag) ans += max(pos-max(pos2,now),0);
				else ans += max(pos2-max(pos3,now),0);
				if(pos2==pos) flag = 1;
				now = pos;
			}
		}
		cout << ans << "\n";
	} 
	return 0;
}
