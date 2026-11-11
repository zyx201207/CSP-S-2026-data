#include<bits/stdc++.h>
using namespace std;
int c,T;
long long n,d;
long long s[2000010];
long long x[2000010];
long long nd,cnt;
void dfs(int now,int dis,int en){
	if(now==en){
		if(dis==nd)cnt++;
		if(dis<nd)nd=dis,cnt=1;
		return;
	}
	int sum=0;
	for(int i=now+1;i<=en;i++){
		sum+=s[i];
		if(sum<=d)dfs(i,dis+1,en);
		else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>T;
	if(c>=11&&c<=12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
				if(i>1)s[i]=x[i]-x[i-1];
			}
			if(s[2]<d&&s[2]*2>=d){
				long long ans=n*n-(n-3)*3;
				cout<<ans<<'\n';
			}
			else cout<<"0\n";
		}
	}
	else{
		while(T--){
			cin>>n>>d;
			long long ans=0;
			for(int i=1;i<=n;i++){
				cin>>x[i];
				if(i>1)s[i]=x[i]-x[i-1];
			}
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					cnt=0,nd=10000000000000000;
					dfs(i,0,j);
					if(cnt==2)ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
