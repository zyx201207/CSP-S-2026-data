#include<bits/stdc++.h>
using namespace std;

const int N=2e6;
const int NN=10;

int C,T;
int n,k;
int sum;
int s[N+5];
int cnt[(1<<NN)+5];
vector<int> e[N+5];

void check(int u,int fa,int l){
	if(l==0&&s[u]==1) l=1,sum++;
	if(l==1&&s[u]==0) l=0;
	for(int v:e[u]){
		if(v==fa) continue;
		check(v,u,l);
	}
}

int calc(int u,int fa,int dis){
	int sn=n+5;
	if(s[u]==1) sn=dis=0;
	for(int v:e[u]){
		if(v==fa) continue;
		int tmp=calc(v,u,dis+1);
		sn=min(sn,tmp);
	}
	sum=max(sum,min(sn,dis));
	return sn+1;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	for(int i=1;i<(1<<NN);i++){
		cnt[i]=cnt[i>>1]+(i&1); 
	}
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		if(C==13||C==14){
			cout<<ceil(((n+1)/2+1-k)*1.0/4)<<"\n";
		}else{
			int ans=n+5;
			for(int now=1;now<(1<<n);now++){
				if(cnt[now]!=k) continue;
				for(int i=1;i<=n;i++){
					if((now>>(i-1))&1) s[i]=1;
					else s[i]=0;
				}
				sum=0;
				check(1,0,0);
				if(sum>2) continue;
				sum=0;
				calc(1,0,n+5);
				ans=min(ans,sum);
			}
			cout<<ans<<"\n";
		}
		for(int i=1;i<=n;i++) e[i].clear();
	}
	return 0;
}
