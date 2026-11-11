#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n , m ,a[N],d[N],ans= 0,ma = -1;
map<int,int> mp;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x){
	if(x == m){
		int p = d[1];
		for(int i=2;i<=x;i++) p = p & d[i];
		ans = max(ans,p);
	}else{
		for(int i=1;i<=n;i++){
			if(mp[i] == 0){
				mp[i] = 1;
				d[x+1] = a[i];
				dfs(x+1);
				mp[i] = 0;
				d[x+1] = 0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma = max(a[i],ma);
	}
	//d[1] = ma;
	sort(a+1,a+1+n,cmp);
	if(m == 1) cout<<a[1];
	else if(m == n){
		int u = a[1];
		for(int i=1;i<=n;i++) u = u & a[i];
		cout<<u; 
	}
	else if(m == 2){
		int ma = -1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i != j) ma = max(ma , a[i] & a[j]);
			}
		}
		cout<<ma;
	}
	else if(n>=20){
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				if(j-1==0) d[j] = max(d[j],a[i]);
				else d[j] = max(d[j],d[j-1] & a[i]);
			}
		}	
		cout<<d[m]<<endl;
	}
	else{
		dfs(0);
		cout<<ans;	
	}
	return 0;
}
