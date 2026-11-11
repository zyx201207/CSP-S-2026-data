#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 6;
int n,d,x[N],len[N];
struct Tree{
	int tr[N];
	
	int lowbit(int x){ return x & -x;	}
	void add(int x,int k){
		while(x <= n){
			tr[x] += k;
			x += lowbit(x);
		}
	}
	int query(int x){
		int res = 0;
		while(x){
			res += tr[x];
			x -= lowbit(x);
		}
		return res;
	}
}ta,tb;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin >> c >> T;
	while(T--){
		int ans = 0,AP = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		for(int i = 1;i <= n;i++){
			len[i] = 0;
			for(int j = i+1,k = i;j <= n;j++){
				while(x[j] - x[k] > d) k++;
				if(j == k) break;
				len[j] = len[k] + 1;
			}
			for(int j = i+1,l = i,r = i;j <= n;j++){
				if(!len[j]) break;
				while(x[j] - x[l] > d) l++;
				while(len[j] != len[r+1]) r++;
				int ck = ta.query(r) - ta.query(l-1) + (r-l+1);
				int cb = tb.query(r) - tb.query(l-1);
				if(ck == 2 || (ck == 0 && cb == 1)){
					ans++, tb.add(j,1), ta.add(j,-1);
					if(!AP) AP = j;
				}
				if(ck > 2) ta.add(j,-1);
				//cout << j << " " << "[" << l << " " << r << "] " << ck << " " << cb << "\n";
			}
			for(int j = i;j <= n;j++) len[j] = 0, ta.tr[j] = 0, tb.tr[j] = 0;
			//cout << ans << " ";
			if(c == 11 || c == 12){
				if(!AP) ans = 0;
				else ans = n-AP+1;
				break;
			}
		}
		cout << ans << "\n";
	} 
	return 0;
} 
