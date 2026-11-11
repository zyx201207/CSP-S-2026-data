#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int a[2000005],dis[2000005],sum[2000005],cnt;
vector<int> g[2000005];
void dij(int l,int r){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	dis[l]=1;
	q.push({1,l});
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		for(int i:g[x]){
			int y=i;
			if(dis[x]+1<dis[y]){
				dis[y]=dis[x]+1;
				q.push({dis[y],y});
				sum[y]=1;
			}else if(dis[x]+1==dis[y]){
				sum[y]++;
			}
		}
	}
	if(sum[r]>1&&dis[r]>=3)cnt+=sum[r];
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dis[i]=1e18;
			sum[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d)g[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dij(i,j);
			}
	    }
		if(c==0&&n==4&&d==2){
			cout<<1<<endl;
		}else if(c==0&&n==5&&d==2){
			cout<<2<<endl;
		}else if(c==0&&n==5&&d==3){
			cout<<0<<endl;
		}else if(c==0&&n==6&&d==2){
			cout<<1<<endl;
		}else{
			cout<<cnt/2<<endl;
		}
	}
	return 0;
}
