#include <bits/stdc++.h>
using namespace std;
#define in(s) freopen(#s ".in","r",stdin)
#define out(s) freopen(#s ".out","w",stdout)
const int N = 5e5+5, M = 3e5+5;

int n,m;
int arr[N];
int las[M];
vector<int> vec[M];
int in[M];
queue<int> que;
int tep;
int ans[M];

signed main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	in(card);
	out(card);
//	scanf("%d%d",&n,&m);
	cin >> n >> m;
//	for(int i=1;i<=n;i++)	scanf("%d",&arr[i]), ans[arr[i]]++;
	for(int i=1;i<=n;i++)	cin >> arr[i], ans[arr[i]]++;
	for(int i=1;i<=n;i++)	las[arr[i]] = i;
	for(int i=1;i<=m;i++){
		if (las[i] < n){
			vec[i].push_back(arr[las[i]+1]);
			in[arr[las[i]+1]]++;
		}
	}
	for(int i=1;i<=m;i++){
		if (!in[i]){
			que.push(i);
		}
	}
	while (!que.empty()){
		tep = que.front(), que.pop();
		for(auto i:vec[tep]){
			in[i]--;
			ans[i] += ans[tep];
			if (!in[i]){
				que.push(i);
			}
		}
	}
//	for(int i=1;i<=m;i++)	printf("%d ",ans[i]);
	for(int i=1;i<=m;i++)	cout << ans[i] << ' ';
	cout << endl; 
	return 0;
}
/*

4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

*/
