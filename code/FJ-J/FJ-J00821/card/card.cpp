#include <bits/stdc++.h>
#define int long long
#define max(a,b) (a>b? a:b)
#define min(a,b) (a<b? a:b)
using namespace std;

int n,m,a[200010],ans[300010];
bool f[300010];
stack<int> st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			st.push(a[j]);
			if(f[a[j]]){
				while(st.top()!=a[j]){
					st.pop();
				}
			}else{
				f[a[j]]=true;
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}
