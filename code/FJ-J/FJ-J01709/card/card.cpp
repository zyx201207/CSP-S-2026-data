#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int cnt[N];
int sum[N];
stack<int> pq;
queue<int> st,q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		st.push(a[i]);
	}
	for(int i=1;i<=n;i++){
		q=st;
		while(!q.empty()){
			int f=q.front();
			q.pop();
			while(cnt[f]==1){
				int now=pq.top();
				pq.pop();
				cnt[now]--;
			}
			cnt[f]++;
			pq.push(f); 
		}
		st.pop();
		for(int i=1;i<=m;i++){
			if(cnt[i]!=0) sum[i]++;
			cnt[i]=0;
		}
		while(pq.size()!=0) pq.pop();
	}
	for(int i=1;i<=m;i++) cout << sum[i] << ' ';
	return 0;
}
