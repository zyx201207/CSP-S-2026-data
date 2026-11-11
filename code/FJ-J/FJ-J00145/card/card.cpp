#include<bits/stdc++.h>
#define long long ll
using namespace std;
const int MAXN = 5e5+5;
int n,m;
queue<int>q;
queue<int>q2;
bool flag[MAXN];
int ans[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		q.push(a);
	}
	while(n--){
		for(int i=1;i<=n;i++){
			if(flag[q.front()]==true){
				int fuck = q.front();
				while(q2.front()!=fuck){
					flag[q2.front()] = false;
					q.push(q2.front());
					q2.pop();
				}
			}else{
				flag[q.front()] = true;
				q2.push(q.front());
				q.pop();
			}
		}
		for(int i=1;i<=m;i++){
			if(flag[i]) ans[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
