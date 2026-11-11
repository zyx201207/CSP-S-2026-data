#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pi pair<int,int>
#define mini pi,vector<pi>,greater<pi>
#define p_q priority_queue
#define fs first
#define se second
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
const int inf = 0x3f3f3f3f3f3f3f3f;

int n, m;
int a[N];
int t[M];
bool pre[M];
stack<int> st;

void solve(int x){
	for(int i = x;i <= n;i++){
		if(pre[a[i]] == 0) st.push(i), pre[a[i]] = 1;
		else{
			while(st.size() and a[st.top()] != a[i]){
				pre[a[st.top()]] = 0;st.pop();
			}
		}
	}
	while(st.size()){
		t[a[st.top()]]++;st.pop();
	}
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin); freopen("card.out","w",stdout);

	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	for(int i = 1;i <= n;i++){
		solve(i);
	}
	
	for(int i = 1;i <= m;i++) cout << t[i] << " ";

	return 0;
}

