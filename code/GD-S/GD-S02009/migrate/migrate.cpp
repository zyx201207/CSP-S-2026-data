#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N=2e6+10,M=5010;
int n,d,a[N],f[M][M],cnt[M][M],ans;
vector<int> e[M];

void init(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)f[i][j]=0x3f3f3f3f3f3f3f3f,cnt[i][j]=0;
		e[i].clear();
	}
	ans=0;
}

int find(int x){
	int l=1,r=n,res=n;
	while(l<=r){
		int mid=l+r>>1;
		if(a[mid]<=x)l=mid+1,res=mid;
		else r=mid-1;
	}
	return res;
}

void bfs(int s,int d[],int cnt[]){
	queue<pair<int,int>> q;
	q.push({s,0});
	while(!q.empty()){
		auto hh=q.front();
		q.pop();
		if(hh.second>d[hh.first])continue;
		else if(hh.second==d[hh.first])cnt[hh.first]++;
		else{
			d[hh.first]=hh.second;
			cnt[hh.first]=1;
		}
//		cout<<s<<":"<<hh.first<<" "<<hh.second<<endl;
		for(int v:e[hh.first]){
//			cout<<"&"<<hh.first<<" "<<v<<endl;
			q.push({v,hh.second+1});
		}
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	system("size migrate.exe");
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>a[i];
		if(C<=10||n<=10){
			init();
			for(int i=1;i<=n;++i){
				int t=find(a[i]+d);
				for(int j=max(i+1,t-2);j<=t;++j){
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
			for(int i=1;i<=n;++i)bfs(i,f[i],cnt[i]);
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					if(cnt[i][j]==2)ans++;
				}
			}
			cout<<ans<<endl;
		}else if(C==11||C==12){
			int t=a[2]-a[1],r=d/t;
			if(r==0)cout<<"0"<<endl;
			else if(r==1)cout<<"0"<<endl; 
			else cout<<max(0ll,n-2*r+1)<<endl;
		}
	}
	return 0;
}

