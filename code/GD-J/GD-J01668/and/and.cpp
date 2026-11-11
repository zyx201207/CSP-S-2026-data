#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e5+10;
bool vis[N];
using LL=long long;
LL a[N][50];
void er(LL x,LL id){
	int w=0;
	while(x!=0){
		a[id][++w]=x%2;
		x/=2;
	}
	return ;
}
LL mpow(LL x){
	if(x==0)return 1;
	LL tmp=mpow(x/2);
	if(x%2)return tmp*tmp*2;
	return tmp*tmp;
}
LL solve(int n,int m){
	LL ans=0;
	for(int i=31;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j][i]&&vis[j]==0)cnt++;
		}
		if(cnt<m)continue;
		for(int j=1;j<=n;j++){
			if(!a[j][i])vis[j]=1;
		}
		ans+=mpow(i-1);
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		er(x,i);
	}
	cout<<solve(n,m);
	return 0;
}
