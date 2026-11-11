#include<iostream>
#include<cstring>
using namespace std;
#define int long long
#define endl '\n'
int id,t,x[2000005],lj[5005][5005];
bool vis[10];
void check(int n,int len,string s){
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			if(i==j)continue;
			lj[s[i]-'0'][s[j]-'0']=lj[s[j]-'0'][s[i]-'0']++;
		}
	}
}
void dfs(int c,int n,int len,string s){
	if(c==n+1)check(n,len,s);
	dfs(c+1,n,len,s);
	vis[c]=true;
	dfs(c+1,n,len+1,s+(char)('0'+c));
	vis[c]=false;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>id>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		int ans=0;
		memset(lj,0,sizeof(lj));
		dfs(1,n,0,"");
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(lj[i][j]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
