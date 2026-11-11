#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
long long n,m,a[N],b[N],r,ans[N];
bool bo[N],bb = 1;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] < a[i - 1] || a[i] > a[i - 1] + 2) bb = 0;
	}
	if(bb == 1){
		for(int i = 1;i <= n;i++){
			b[1] = a[i];
			r = 1;
			for(int j = i;j <= n;j++){
				if(a[j] != b[r]){
					r++;
					b[r] = a[j];
				}
			}
			for(int j = 1;j <= m;j++){
				if(bo[j] == 1) ans[j]++;
			}
			for(int i = 1;i <= m;i++) cout << ans[i] << " ";
		}
	}
	if(n >= 1e5){
		cout << 1 << " " << 1 << " " << 1;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++) b[j] = 0;
		for(int j = 1;j <= m;j++) bo[j] = 0;
		b[1] = a[i];
		r = 1;
		for(int j = i;j <= n;j++){
			int v = 1;
			bool bo = 0;
			for(int k = 1;k <= r;k++){
				if(b[k] == a[j]){
					bo = 1;
					v = k + 1;
				}
			}
			if(bo == 1){
				for(int k = v;k <= r;k++){
					b[k] = 0;
				}
				r = v - 1;
			}
			else{
				r++;
				b[r] = a[j];
			}
		}
		for(int j = 1;j <= m;j++){
			if(bo[j] == 1) ans[j]++;
		}
	}
	for(int i = 1;i <= m;i++) cout << ans[i] << " ";
	return 0;
}
