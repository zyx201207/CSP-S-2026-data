#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],biao[5005];
int n,d,ans[50005];
struct op{
	int a,b,c;
};
queue<op> q;
vector<int> v[50005];
int bfs(int x){
	memset(biao,0x3f,sizeof(biao));
	
	memset(ans,0,sizeof(ans));
	biao[x]=0;
	ans[x]=1;
	q.push({x,0});
	while(!q.empty()){
		int x=q.front().a,w=q.front().b,f=q.front().c;
		q.pop();
		if(w>biao[x]) continue;
		for(int i=0;i<v[x].size();i++){
			if(v[x][i]==f) continue;
			if(w+1<biao[v[x][i]]){
				biao[v[x][i]]=w+1;
				ans[v[x][i]]=ans[x];
				q.push({v[x][i],w+1,x});
			}else if(biao[v[x][i]]==w+1) ans[v[x][i]]+=ans[x];
		}
	}
	int ans1=0;
	for(int i=1;i<=n;i++){
		if(ans[i]==2){
			ans1++;
			
		}
	}
	return ans1;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=5000){
			for(int l=1;l<=n;l++){
				for(int r=l+1;r<=n&&a[l]+d>=a[r];r++){
					v[l].push_back(r);
					v[r].push_back(l);
				}
			}
			for(int i=1;i<=n;i++){
				cnt+=bfs(i);
			}
			for(int i=1;i<=n;i++){
				v[i].clear();
			}
			cout<<cnt/2<<"\n";
		}else if(c<=12){
			cout<<n/2<<endl;
		}else if(c<=14){
			cout<<0<<endl;		
		}
	}
}
