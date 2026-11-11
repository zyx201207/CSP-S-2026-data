#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif
int r(){
	int f=1,k=0,c=gc();
	for(;!isdigit(c);c=gc())	if(c == '-')	f = -1;
	for(;isdigit(c);c=gc())		k=k*10+(c&15);
	return f*k;
}
ll c,T,n,d;
ll a[10004];
vector <int> arr[10004];
ll arr_t[10004];
ll arr_l[10004];
struct Q{
	ll l,v;
	bool operator > (const Q &a)const{return l > a.l;}
};
void spfa(int s){
	for(int i=0;i<=n;i++){
		arr_t[i] = 0;
		arr_l[i] = 1e9;
	}
	priority_queue <Q , vector <Q> , greater<Q> > q;
	q.push({0,s});
	ll maxx = 1e9;
	while(!q.empty()){
		Q now = q.top();
		q.pop();
		if(now.l >= maxx)	break;
		for(int i=0;i<arr[now.v].size();i++){
			ll v = arr[now.v][i];
			if(arr_l[v] >= now.l+1){
				if(arr_l[v] == now.l+1){
					arr_t[v]++;
				}
				else{
					arr_l[v] = now.l+1;
					arr_t[v] = 1;
					q.push({now.l+1,arr[now.v][i]});
				}
			}
		}
	}
}
ll ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin >> c >> T;
	while(T--){
		if(c == 13 || c == 14){
			ans = 0;
			cin >> n >> d;
			for(int i=0;i<=n;i++){
				a[i] = 0;
			}
			for(int i=1;i<=n;i++){
				cin >> a[i];
			}
			int sw = lower_bound(a+1,a+1+n,a[n]-d) - a+1;
			for(int i=sw;i<=n;i++){
				int w = lower_bound(a+1,a+sw,a[i]-d) - a;
				if(i - w == 2){
					ans += w-1;
				}
			}
			cout << ans << endl;
		}
		else{
			ans = 0;
			cin >> n >> d;
			for(int i=1;i<=n;i++){
				cin >> a[i];
			}
			for(int i=1;i<n;i++){
				int r = i+1;
				while(a[i] + d >= a[r] && r<=n){
					arr[i].push_back(r);
					r++;
				}
			}
			for(int i=1;i<=n-3;i++){
				spfa(i);
				for(int j=i+3;j<=n;j++){
					if(arr_t[j] == 2){
						ans++;
					}
				}
			}
			cout << ans << endl; 
			for(int i=0;i<=n;i++){
				arr[i].clear();
				a[i] = 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
