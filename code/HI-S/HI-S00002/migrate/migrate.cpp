#include<bits/stdc++.h>
using namespace std;
long long a[200005];
vector<int> s[200005];
int sum[5005][5005],an[5005][5005];
bool bj[5005][5005];
void bfs(int x){
	queue<int>q;
	q.push(x);
	an[x][x]=0;
	bj[x][x]=1;
	sum[x][x]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int j=0;j<s[now].size();j++){
			int i=s[now][j];
			if(bj[x][i]){
				if(an[x][i]==an[x][now]+1) sum[x][i]+=sum[x][now];
			}else{
				an[x][i]=an[x][now]+1;
				sum[x][i]=sum[x][now];
				bj[x][i]=1;
				q.push(i);
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s[i].clear();
		} 
		for(int i=1;i<=n;i++)
		   for(int j=i+1;j<=n;j++)
		       an[i][j]=an[j][i]=bj[i][j]=bj[j][i]=sum[i][j]=sum[j][i]=0;
		for(int i=1;i<=n;i++)
		    for(int j=i+1;j<=n;j++) 
		       if(a[j]-a[i]<=d){
		       	   s[i].push_back(j);
		       	   s[j].push_back(i);
			   }
		for(int i=1;i<=n;i++){
			bfs(i);
		   	for(int j=1;j<=n;j++){
		   		if(i==j) continue;
		   		if(sum[i][j]==2){
		   			ans++;
				}
		   		
			}
		}
		ans/=2;
		cout<<ans<<"\n";
	}
	return 0;
}
