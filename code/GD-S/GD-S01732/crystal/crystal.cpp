#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
long long a[N],ans,m,res,pre[N];
bool mark = 1,vis[N];
void sps(){//处理等差数列(A∈B) 
	long long d = llabs(a[2] - a[1]),cost = 0,tim = m / d;
//	cerr << tim << '\n';
	for(int i = 1;i <= n;i++){
		cost += i - 1;
		if(cost > tim)break;
		ans++;
	}
	cout << ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
		if(i >= 3 && !(a[i] - a[i - 1] == a[i - 1] - a[i - 2])){
			mark = 0;
		}
	} 
	if(mark){
		sps();
		return 0;
	}//cout << "cut"; 
	sort(a + 1,a + 1 + n);
	int l = 1;
	for(int i = 1;i <= n;i++){
		while(l <= i && (i - l + 1) * a[i] - (pre[i] - pre[l - 1]) > m){
			l++;
		}
		ans = max(ans,(long long)i - (long long)l + 1LL) ;
	}
	cout << ans;
	return 0;
} 
