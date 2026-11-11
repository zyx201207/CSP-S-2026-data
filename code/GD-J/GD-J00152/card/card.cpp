#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int b[500005];
int c[500005]; 
int f[500005];
int cc;
struct pi{
	int l,r,id;
}s[500005];
vector<int>E[500005];
map<int,int>mp;
bool cmp(pi x,pi y){
	if(x.id == y.id){
		if(x.l == y.l){
			return x.r < y.r;
		}
		return x.l < y.l;
	}
	return x.id < y.id;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		E[a[i]].push_back(i);
	}
	if(n <= 5000){
		for(int i = 1 ; i <= n ; i ++){
			stack<int>q;
			mp.clear();
			for(int j = i ; j <= n ; j ++){
				if(mp[a[j]]){
					while(!q.empty() && q.top() != a[j]){
						mp[q.top()] = 0;
						q.pop();
					}
				}else{
					mp[a[j]] = 1;
					q.push(a[j]);
				}
			}
			while(!q.empty()){
	//			cout << i << " " << q.top() << "\n";
				f[q.top()] ++;
				q.pop();
			}
		}
		for(int i = 1 ; i <= m ; i ++){
			cout << f[i] << " ";
		}	
		return 0;
	}
	for(int i = 1 ; i <= n ; i ++){
		if(E[a[i]].size() - 1 != c[a[i]]){
			b[i + 1] = i;
			c[a[i]] ++;
		}
		if(b[i] != 0)continue;
		b[i] = b[i - 1];
	}
	for(int i = 1 ; i <= n ; i ++){
		s[++cc].l = b[i];
		s[cc].r = i;
		s[cc].id = a[i];
	}
	sort(s + 1 , s + 1 + n , cmp);
	int l = 0,r = 0;
	for(int i = 1 ; i <= n ; i ++){
		if(s[i].id != s[i - 1].id){
			l = s[i].l;
			r = s[i].r;
			continue;
		}
		if(s[i].l < s[i - 1].r){
			r = s[i].r;
		}else{
			f[s[i].id] += r - l;
			l = s[i].l;
			r = s[i].r;
		}
	}
	for(int i = 1 ; i <= m ; i ++){
		cout << f[i] << " ";
	}
	return 0;
}

