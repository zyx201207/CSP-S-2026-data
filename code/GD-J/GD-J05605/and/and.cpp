#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
long long n,m,x,a[N],ans,maxn,s[N],f[N],p,h;
bool b[N][35],bx[N],bq[N];
bool cmp(long long a,long long b){
	return a > b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	memset(b,0,sizeof(b));
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		//cout << a[i] << " ";
	}
	sort(a + 1,a + n + 1,cmp);
	for(int i = 1;i <= n;i++){
		long long v = 0;
		x = a[i];
		//cout << a[i] << " ";
		while(x){
			if(x % 2 == 0){
				v++;
				b[i][v] = 0;
			}
			else{
				v++;
				b[i][v] = 1;	
			}
			x /= 2;
		}
		//for(int j = 1;j <= v;j++) b[i][j] = bo[v - j + 1];
		maxn = max(maxn,v);
		//cout << a[i] << " ";
		//for(int j = 1;j <= 16;j++) cout << b[i][j];
		//cout << endl;
	}
	//yuchuli
	bool boo = 0;
	for(int i = maxn;i >= 1;i--){
		h = 0;
		for(int j = 1;j <= n;j++){
			if(b[j][i] == 1) h++;
		}
		//cout << h << " ";
		if(h >= m){
			maxn = i;
			boo = 1;
			if(i == 1) ans = 1;
			else ans = (1ll << (i - 1));
			break;
		}
		//cout << endl;
	}
	//cout << ans << "$$$$$$$$$$$$$$$$" << endl;
	if(boo == 0){
		cout << 0;
		return 0;
	}
	//kaoshijisuan
	for(int i = 1;i <= n;i++){
		if(b[i][maxn] == 1){
			p++;
			s[p] = i;
			bx[i] = 1;
			//cout << a[i] << " " << b[i][maxn] << " ";
		}
	}
	//cout << p << "$$$$$$$$$$$$$$$$" << endl;
	for(int i = maxn - 1;i >= 1;i--){
		memset(bq,0,sizeof(bq));
		h = 0;
		for(int j = 1;j <= n;j++){
			if(b[j][i] == 1 && bx[j] == 1){
				h++;
				bq[j] = 1;
			}
		}
		//cout << h << "%%%" << endl;
		if(h >= m){
			if(i == 1) ans += 1;
			else ans += (1ll << (i - 1));
			if(h < p){
				for(int k = 1;k <= p;k++){
					if(bx[s[k]] == 1 && bq[s[k]] == 0){
						bx[s[k]] = 0;
					}
				}
				p = h;
			}
		}
		//cout << ans << endl;
	}
	cout << ans;
	return 0;
}
