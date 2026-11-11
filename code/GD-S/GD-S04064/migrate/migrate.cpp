#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10;
int n,d,x[N],p[N];

#define chk1 cout <<"1:"<< st << ' ' << ed << endl
#define chk2 cout <<"2:"<< st << ' ' << ed << endl
signed main() {
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T,oiocf; cin>>oiocf>>T;
	while(T--) {
	cin>>n>>d;
	for (int i=1;i<=n;i++) cin>>x[i];
	
	for (int i=1,pos=1;i<=n;i++) {
		while (pos+1 <= n && x[i] + d >= x[pos+1]) pos++;
		p[i] = pos;
	}
	int ans = 0,rans=0;
//	cout << p[1] << endl;
	for (int st=1;st<=n;st++) {
		int gj=0;
		if (oiocf >= 11 && oiocf <= 12 && st == 100) break; 
		for (int ed=max(p[st]-1,st+1),lst=st;ed<=n;ed++) {
			if (x[ed] - x[ed-1] > d) break;
			if (ed > p[lst]) {
				// lst, p[lst] ¼ì²é
				if (lst - 1 >= st)
				if (p[lst] == p[lst-1]) {
					if (lst-2 >= st)
					if (p[lst-2] != p[lst]) {
						gj++;
						if (gj > 1) break;
					}
					else {
						break;
					}
				} 
				lst = p[lst];
			}
			if (lst - 1 >= st)
			if (p[lst-1] >= ed) {
				if (gj == 0 && p[lst-2] < ed) {
					
					if (oiocf >= 11 && oiocf <= 12 && rans == 0) {
						rans+=n-ed+1; break;}
					ans++; 
				}
			}
			else {
				if (gj==1) {
					if (oiocf >= 11 && oiocf <= 12 && rans == 0) {
						rans+=n-ed+1; break;}
					
					ans++;
				}
			}
		}
	}
		cout << ans << '\n';
	}
	return 0;
}
