#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2*1e5+10;
int n,m,a[maxn],ans[maxn][35],t[maxn],sum=1;
bool cmp(int x,int y){
	return x>y;
}
void turn(int x){
	int maxx=0,y=a[x];
	while(y!=0){
		maxx++;
		ans[x][maxx]=y%2;
		y/=2;
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=30;i++)    sum*=2;
	sum--;
	for(int i=1;i<=n;i++)    cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)    turn(i);
	int mob=0,wei;
	for(int i=31;i>0;i--){
		mob=0;
		for(int j=1;j<=n;j++){
			if(ans[j][i]==1&&t[j]==0)    mob++;
		}
		if(mob>=m){
			for(int j=1;j<=n;j++){
				if(ans[j][i]==0)    t[j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(t[i]==0)   sum&=a[i]; 
	}
	cout<<sum;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)    solve();
}
