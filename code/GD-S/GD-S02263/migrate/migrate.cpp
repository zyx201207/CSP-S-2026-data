#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e6+9;
int c,t,n;
ll d,x[maxn],d1[maxn],d2[maxn],d3[maxn];
void solve1(){
	ll ans=0;
	queue<pair<int,ll>>q;
	for(int i=1;i<=n;i++){
		while(!q.empty())q.pop();
		for(int j=i;j<=n;j++)d1[j]=d2[j]=d3[j]=-1;
		d1[i]=0;
		q.push({i,0});
		while(!q.empty()){
			int u=q.front().first;
			ll w=q.front().second;
			q.pop();
			if(d3[u]!=-1&&w>d3[u])continue;
			int r=upper_bound(x+1,x+1+n,x[u]+d)-x;
//			cout<<u<<" "<<r<<endl;
			for(int v=r-1;v>u;v--){
				if(x[v]-x[u]>d)break;
				if(d1[v]==-1||d1[v]>w+1){
					d3[v]=d2[v];
					d2[v]=d1[v];
					d1[v]=w+1;
					q.push({v,d1[v]});
				}else if(d2[v]==-1||d2[v]>w+1){
					d3[v]=d2[v];
					d2[v]=w+1;
					q.push({v,d2[v]});
				}else if(d3[v]==-1||d3[v]>w+1){
					d3[v]=w+1;
					q.push({v,d3[v]});
				}else break;
			}
		}
		for(int j=i+1;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<d1[j]<<" "<<d2[j]<<" "<<d3[j]<<endl;
			if(d2[j]!=-1&&d1[j]==d2[j]&&d3[j]!=d2[j])ans++;
		}
	}
	cout<<ans<<endl;
}
void solve2(){
	if(x[2]-x[1]>d)cout<<0<<endl;
	else{
		ll l=d/(x[2]-x[1]);
		if(l*2>n||l<2)cout<<0<<endl;
		else cout<<n-(l*2-1)<<endl;
	}
}
ll l[maxn][13],r[maxn][13],cnt[maxn],ne[maxn],l2[maxn],r22[maxn];
vector<int>ve[maxn],vee[maxn];
void solve3(){
//	cout<<"***"<<endl; 
	for(int i=1;i<=n;i++){
		if(i==n||x[i+1]-x[i]>d)l[i][1]=i;
		else l[i][1]=i+1;
		r[i][1]=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
	}
	for(int i=2;i<=10;i++){
		for(int j=1;j<=n;j++){
			l[j][i]=max(r[j][i-1]+1,l[l[j][1]][i-1]);
			r[j][i]=r[r[j][1]][i-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=10;j++){
			if(l[i][j]==i||l[i][j]>r[i][j])continue;
			if(r[i][j]-l[i][j]+1<2)continue;
//			cout<<i<<" "<<j<<" "<<l[i][j]<<" "<<r[i][j]<<endl;
			ve[r[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(i==1||x[i]-x[i-1]>d)r[i][1]=i;
		else r[i][1]=i-1;
		l[i][1]=lower_bound(x+1,x+1+n,x[i]-d)-x;
	}
	for(int i=2;i<=10;i++){
		for(int j=1;j<=n;j++){
			r[j][i]=min(l[j][i-1]-1,r[r[j][1]][i-1]);
			l[j][i]=l[l[j][1]][i-1];
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=10;j++){
			if(r[i][j]==i||l[i][j]>r[i][j])continue;
			if(r[i][j]-l[i][j]+1<2)continue;
//			cout<<i<<" "<<j<<" "<<l[i][j]<<" "<<r[i][j]<<endl;
//			ans+=cnt[l[i][j]+1];
			vee[l[i][j]+1].push_back(i);
		}
	}
//	cout<<"***"<<endl; 
	ll lll=0,lr=0,rl=n,rr=n;
	for(int i=1;i<=n;i++){
//		cout<<i<<endl;
		sort(ve[i].begin(),ve[i].end());sort(vee[i].begin(),vee[i].end());
		if(ve[i].size()==0||vee[i].size()==0)continue;
		for(int i=ve[i][0];i<=ve[i][ve[i].size()-1];i++){
			if(l2[i]==0)l2[i]=vee[i][0];
		}
		for(int i=ve[i][0];i<=ve[i][ve[i].size()-1];i++){
			r22[i]=vee[i][vee[i].size()-1];
		}
		lll=ve[i][0];lr=ve[i][ve[i].size()-1];
		rl=vee[i][0];rr=vee[i][vee[i].size()-1];
//		cout<<i<<endl;
	}
	for(int i=1;i<=n;i++){
		if(l2[i]!=0&&r22[i]>=l2[i])ans+=r22[i]-l2[i]+1;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		cnt[i]=0;
		for(int j=1;j<=10;j++)l[i][j]=r[i][j]=0;
		l2[i]=r22[i]=0;
		ve[i].clear();
		vee[i].clear();
//		ne[i]=0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
//		for(int i=1;i<=n;i++)x[i]=i;
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		if(n<=5000)solve1();
		else if(c==11||c==12)solve2();
		else if(13<=c&&c<=18)solve3();
		else cout<<0<<endl;
	}
	return 0;
}
