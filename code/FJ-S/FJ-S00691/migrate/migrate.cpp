#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
long long n,d,x[N],sum[N],s;
bool flag,book[N];
void dfs(int u,int v,int step){
	if(u==v){
		sum[++s]=step;
		return;
	}
	int lt=u,rt=u;
	while(lt>1 && abs(x[lt]-x[u])<=d) lt--;
	while(rt<n && abs(x[rt]-x[u])<=d) rt++;
	for(int i=lt;i<=rt;i++){
		if(!book[i]){
			book[i]=true;
			dfs(i,v,step+1);
			book[i]=false;
		}
	}
}
bool check(int u,int v){
	memset(book,false,sizeof(book));
	book[u]=true;
	dfs(u,v,0);
	sort(sum+1,sum+1+s);
	if(s>=2 && sum[1]==sum[2] && sum[2]!=sum[3])
		return true;
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				s=0;
				memset(sum,0,sizeof(sum));
				if(check(i,j)){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
