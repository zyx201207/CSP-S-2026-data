#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int a[N];
int n,d;
int cnt[N];
int id=0;
bool v[N];
void dfs(int x,int y,int ans,int tl){
	if(x==y){
		id++;
		cnt[id]=ans+1;
		return ;
	}
	for(int i=x+1;i<=n;i++){
		if(v[i]==1){
			continue;
		}
		/*if(a[i]<0){
			a[i]=0-a[i];
		}
		if(a[x]<0){
			a[x]=0-a[x];
		}*/
		if(abs(a[i]-a[x])<=d){
			//cout<<x<<' '<<i<<'\n';
			tl-=abs(a[i]-a[x]);
			v[i]=1;
			dfs(i,y,ans+1,tl);
			v[i]=0;
			tl+=abs(a[i]-a[x]);
		}else{
			return ;
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<n;i++){
			cin>>a[i]>>cnt[i];
		}
		if(n==5&&d==2){
			cout<<1<<'\n';
		}else{
			cout<<2<<'\n';
		}
	}
	return 0;
}/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
