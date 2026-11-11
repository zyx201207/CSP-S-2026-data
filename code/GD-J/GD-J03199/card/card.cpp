#include <bits/stdc++.h>
using namespace std;
template<typename T>inline void rd(T &x){int f=1;char ch;for(;ch<'0'||ch>'9';ch=getchar()){if(ch=='-')f=-1;}x=0;for(;ch>='0'&&ch<='9';ch=getchar()){x=x*10+(ch-'0');}if(f==-1 && !std::is_unsigned<T>::value) x*=f;}
constexpr int N = 5e5+5; int a[N];
constexpr int M = 3e5+5; bool vis[M];
int ans[M];
int n, m;/*
void bug(const vector<int> &v){
	cout << "[DEBUG] ";
	for(auto x:v) cout << x << ' ';
	cout << '\n';
}*/
void game(int t){
	vector<int> v;
	v.reserve(m+1);
	
	for(int i = 1; i <= m; i ++) vis[i] = 0;
	for(int i = t; i <= n; i ++){
		if(vis[a[i]] == 0){
			v.push_back(a[i]);
			vis[a[i]] = 1;
		}else{
			
			while(1){
				if(v.empty()) break;
				int x = v.back();
				v.pop_back();
				vis[x] = 0;
				if(x == a[i]){
					break;
				}
			}
			v.push_back(a[i]);
			vis[a[i]] = 1;
		}
		//bug(v);
	}
	if(v.empty()) return;
	for(auto x:v){
		ans[x] ++;
	}
	/*
	cout << "[ans] = ";
	for(int i = 1; i <= m; i ++){
		cout << ans[i] << ' ';
	}
	cout << '\n';*/
	return ;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	 
	rd(n); rd(m);
	for(int i = 1; i <= n; i ++){
		rd(a[i]);
	}
	
	for(int i = 1; i <= n; i ++){
		game(i);
	}
	
	for(int i = 1; i <= m; i ++){
		cout << ans[i] << ' ';
	}
	return 0;
}
/*
4 3
1 2 1 3
*/

/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
