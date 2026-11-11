#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
const int N = 2000010;
int c,T,n,d,ans,cnt;
ll x[N];
int a[N];
void dfs(int nw,int e,int step){
	if(nw==e){
		a[++cnt] = step;
		return;
	}
	for(int i = nw+1;i <= e;i++){
		if(x[i]-x[nw]<=d)dfs(i,e,step+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> T;
	while(T--){
		ans = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)cin >> x[i];
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				cnt = 0;
				dfs(i,j,0);
				int ln = 1;
				sort(a+1,a+1+cnt);
				for(int i = 2;i <= cnt;i++){
					if(a[i]!=a[i-1])break;
					ln++;
				}
				if(ln==2)ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
