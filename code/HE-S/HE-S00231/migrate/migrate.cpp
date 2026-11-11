#include <bits/stdc++.h>
#define int long long
#define fr first
#define se second
#define pii pair<int,int>
#define vt vector
#define mkp make_pair
#define elainya_stars return
using namespace std;
const int inf=INT_MAX;

const int N=2e6+7;
int n,k,rp=0;
int v[N]={0};
void dfs(int st,int ed,int len){
	if(st==ed){
		if(len==0) rp++;
		elainya_stars;
	}
	for(int i=st+1;i<=ed;i++) if(v[i]-v[st]<=k) dfs(i,ed,len-1);
}
bool check(int a,int b){
	for(int i=b-a+1;i>=1;i--){
		rp=0;
		dfs(a,b,i);
		if(rp==2) elainya_stars 1;
	}
	elainya_stars 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i=1;i<=n;i++) cin >> v[i];
		int ct=0;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(check(i,j)) ct++;
		cout << ct << endl;
	}
	elainya_stars 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
																																						
																																						
																																						
																																						
																																						
																																						
																																						
																																						
																																						
																																						
																																						
																																						

