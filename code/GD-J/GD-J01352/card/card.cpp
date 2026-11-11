#include<bits/stdc++.h>
using namespace std;
int n, m, k, a[500005], go[500005], vis[500005], res[500005], cnt, ans, sum;
int b[500005], c[500005];
struct node{
	int x, y, ans;
}d[500005];
vector<int> v;
void merge(node x, int y){
	if(x.y >= d[y].x){
		if(d[y].x >= x.x){
			d[y].ans += (d[y].x - x.x);
			d[y].x = x.x;
		}
	}else{
		d[y].x = x.x;
		d[y].y = x.y;
		d[y].ans += x.ans;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(i > 1 && a[i] >= a[i - 1]) cnt ++;
		if(i > 1 && a[i] != a[i - 1]) sum ++;
	}
	for(int i = n;i >= 1;i --){
		go[i] = vis[a[i]];
		vis[a[i]] = i;
	} 
	if(n <= 5000){
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= m;j ++) vis[j] = 0;
			for(int j = i;j <= n;){
				vis[a[j]] = 1;
				if(!go[j]) j ++;
				else j = go[j];
			}
			for(int i = 1;i <= m;i ++){
				res[i] += (vis[i] > 0);
			}
		}
		for(int i = 1;i <= m;i ++) cout << res[i] << " ";
	}else if(cnt == n - 1){
		for(int i = 1;i <= n;i ++){
			res[b[i]] = max(res[b[i]], i);
		}
		for(int i = 1;i <= m;i ++){
			cout << res[i] << " ";
		}
	}else if(sum <= 5000){
		b[++ k] = a[1], c[k] = 1; 
		for(int i = 2;i <= n;i ++){
			if(a[i] != a[i - 1]) b[++ k] = a[i], c[k] = 1;
			else c[k] ++;
		}
		for(int i = 1;i <= m;i ++) vis[i] = 0;
		for(int i = k;i >= 1;i --){
			go[i] = vis[b[i]];
			vis[b[i]] = i;
		}
		for(int i = 1;i <= k;i ++){
			for(int j = 1;j <= m;j ++) vis[j] = 0;
			for(int j = i;j <= k;){
				vis[b[j]] = 1;
				if(!go[j]) j ++;
				else j = go[j];
			}
			for(int j = 1;j <= m;j ++){
				res[j] += (vis[j] > 0) * c[i];
			}
		}
		for(int i = 1;i <= m;i ++) cout << res[i] << " ";
	}else{
		for(int i = 1;i <= n;i ++){
			b[i] = a[i];
		}
		for(int i = 1;i <= k;i ++) d[i] = (node){n + 1, n + 1, 0};
		for(int i = n;i >= 1;i --){
			auto t = upper_bound(v.begin(), v.end(), i) - v.begin() - 1;
			if(t == -1 || (t == 0 && v[t] == i)){
				node q = (node){1, i, i};
				merge(q, b[i]);
				if(go[i]) v.insert(lower_bound(v.begin(), v.end(), go[i]), go[i]);
			}else{
				node q;
				if(v[t] == i) q = (node){v[t - 1] + 1, i, i - v[t - 1]};
				else q = (node){v[t] + 1, i, i - v[t]};
				merge(q, b[i]);
				if(go[i]) v.insert(lower_bound(v.begin(), v.end(), go[i]), go[i]);
			}
		}
		for(int i = 1;i <= m;i ++){
			cout << d[i].ans << " ";
		}
	}
	return 0;
}
