#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,t;
int n,d,mn,s;
int x[200005];
int p[1005][1005];
void dfs(int w,int y,int step){
	if(w==y){
		if(step<mn)mn=step,s=1;
		else if(step==mn)s++;
		return;
	}
	if(step>mn)return;
	for(int i=1;i<=y-w;i++){
		if(x[w+i]-x[w]<=d){
			dfs(w+i,y,step+1);
		}
		else break;
	}
	return;
}
signed main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>1&&x[i]-x[i-1]>d)p[i-1][i]=1;
		}
		if(c==11||c==12){
			if(d>=2*(x[2]-x[1]))cout<<n-d/(x[2]-x[1])*2+1<<endl;
			else cout<<0<<endl;		
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					mn=1e9+10,s=0;
					dfs(i,j,0);
					if(s==2)ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
