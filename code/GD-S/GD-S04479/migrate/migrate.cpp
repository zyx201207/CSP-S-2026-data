#include<bits/stdc++.h>
using namespace std;
const int N=5007;
long long c,t,n,d,sx,ex,ans,bans,a[N];
map<long long,bool> mp;
long long minn,minnum;
void dfs(int x,int y){
	if(x==ex){
		ans++;
		if(y<minn){
			minn=y;
			minnum=1;
		}
		else if(y==minn) minnum++;
		return;
	}
	for(int i=d;i>=1;i--){
		if(mp[x+i]==1&&x+i<=ex&&y+1<=minn){
			dfs(x+i,y+1);
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		mp.clear();bans=0;
		for(int i=1,x;i<=n;i++){
			cin>>x;
			mp[x]=1;
			a[i]=x;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=0;minn=1e18;minnum=0;
				sx=a[i],ex=a[j];
				dfs(sx,0);
				if(ans==2) bans++;
			}
		}
		cout<<bans<<"\n";
	}
	return 0;
}

