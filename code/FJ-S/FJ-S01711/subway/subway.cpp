#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int c,n,m,d,q,t[N],k[N],l[N],ans=INT_MAX;
vector<int>a[N];
void dfs(int step,int x,int id){
	v[x].push_back(step);
	for(int i=id+1;i<=n;i++){
		if(a[i]-a[id]<=d)dfs(step+1,a[i],i);
		else break;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>t;
while(t--){
	cin>>n>>d;
	for(int i =1;i <=n;i++)cin>>a[i];
	dfs(0,1,1);
	ans=0;
	for(int i = 1;i <= n;i++){
		sort(v[i].begin(),v[i].end());
		if(v[i][0]==v[i][1]&&v[i][0]==v[i][2]&&v[i][0])ans++;
	}
	cout<<ans;
}
	return 0;
}
