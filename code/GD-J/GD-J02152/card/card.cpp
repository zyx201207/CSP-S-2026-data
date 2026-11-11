#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500005;
int n, m, a[N];
struct node{
	int l, r, nxt, val;
}ans[N];
int lst[N], ru[N], d[N], o[N];
queue<int> q;
signed main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int i = 1; i <= m; i ++) lst[i] = n + 1;
	int z = -1, wz = -1;
	for(int i = n; i >= 1; i --){
		if(lst[a[i]]!=n+1){
			z = i;
			wz = lst[a[i]];
		}
		else lst[a[i]] = i;
		if(z==-1){
			ans[i] = {i,n,n+1,1};
			continue;
		}
		ans[i] = {i, z, wz+1, 1};
		ru[wz+1] ++;
	}
	for(int i = 1; i <= n; i ++){
		if(!ru[i]){
			q.push(i);
		}
	}
	while(!q.empty()){
		int x = q.front(); q.pop();
		d[ans[x].l] += ans[x].val;
		d[ans[x].r+1] -= ans[x].val;
		if(ans[x].nxt>n)continue;
		else {
			ans[ans[x].nxt].val += ans[x].val;
			ru[ans[x].nxt] --;
			if(!ru[ans[x].nxt]){
				q.push(ans[x].nxt);
			}
		}
	}
	int now = 0;
	for(int i = 0; i <= n; i ++){
		now += d[i];
		o[a[i]] += now;
	}
	for(int i = 1; i <= m; i ++){
		cout << o[i] << " ";
	}
	return 0; 
} 

