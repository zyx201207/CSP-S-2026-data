#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FILE(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);
signed main(){
	FILE("migrate")
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==0){
		while(t--){
			int n,d;
			cin>>n>>d;
			int a[n];
			for(int& i:a)cin>>i;
			int x=d/(a[1]-a[0]);
			if(d<2)cout<<"0\n";
			else cout<<n-2*x-1<<'\n';
//cout<<n<<' '<<d<<' '<<a[1]-a[0]<<'\n';
		}
		return 0;
	}
	while(t--){
		int n,d;
		cin>>n>>d;
		int a[n],ans=0;
		for(int& i:a)cin>>i;
		vector<int>v[n];
		for(int i=0;i<n;i++)
			for(int j=i+1;a[j]-a[i]<=d&&j<n;j++)
				v[i].push_back(j);
		for(int i=0;i<n;i++){
			int dis[n]{},num[n]{};
			fill(dis,dis+n,-1);
			dis[i]=0;num[i]=1;
			queue<int>q;
			q.push(i);
			while(!q.empty()){
				int tp=q.front();q.pop();
				for(int j:v[tp])
					if(!num[j]){
						dis[j]=dis[tp]+1;
						num[j]=1;
						q.push(j);
					}else if(dis[tp]+1==dis[j])num[j]++;
			}
			for(int j=0;j<n;j++)
				if(num[j]==2)ans++;
		}cout<<ans<<'\n';
	}
}
