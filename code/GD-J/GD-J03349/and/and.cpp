#include <bits/stdc++.h>
using namespace std;
#define in(s) freopen(#s ".in","r",stdin)
#define out(s) freopen(#s ".out","w",stdout)
#define int long long
typedef pair<int,int> pii;
const int N = 2e5+5, LN = 30;

int n,m;
int arr[N][LN+5];
int tol[LN+5];
int cnt;
int ans;

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	in(and);
	out(and);
//	scanf("%lld%lld",&n,&m);
	cin >> n >> m;
//	for(int i=1;i<=n;i++)	scanf("%lld",&arr[i][LN]);
	for(int i=1;i<=n;i++)	cin >> arr[i][LN];
	tol[LN] = n;
	for(int j=LN-1;j>=0;j--){
		cnt = 0;
		for(int i=1;i<=tol[j+1];i++)	cnt += (arr[i][j+1]>>j)&1;
//		cout << cnt << '\n';
		if (cnt >= m){
			for(int i=1;i<=tol[j+1];i++){
				if ((arr[i][j+1]>>j)&1){
					arr[++tol[j]][j] = arr[i][j+1];
				}
			}
		}else{
			for(int i=1;i<=tol[j+1];i++){
				arr[++tol[j]][j] = arr[i][j+1];
			}
		}
//		cout << j << " : \n";
//		for(int i=1;i<=tol[j];i++)	cout << arr[i][j] << ' ';
//		cout << '\n';
		ans |= (cnt >= m)<<j;
	}
	printf("%lld",ans);
	return 0;
}
/*

4 2
3 15 12 12


5 3
31 3 1 15 7


*/
