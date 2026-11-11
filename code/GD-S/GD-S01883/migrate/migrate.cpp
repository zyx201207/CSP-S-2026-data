#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[2000005],pos[2000005],dis[505][505],cnt[505][505];
int jp[2000005][35];
struct edge{
	long long x,val;
};
void bfs(long long col){
	queue<edge> q;
	q.push({col,0}),dis[col][col]=0,cnt[col][col]=1;
	while(!q.empty()){
		long long x=q.front().x,tmp=q.front().val;
		q.pop();
		for(long long j=x+1;j<=min(n,pos[x]);j++){
			if(dis[col][j]>tmp+1){
				dis[col][j]=tmp+1,cnt[col][j]=cnt[col][x],q.push({j,tmp+1});
			}
			else if(dis[col][j]==tmp+1)cnt[col][j]+=cnt[col][x];
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++)cin>>a[i];
		if(n==1){
			cout<<0<<'\n';
			continue;
		}
		a[n+1]=a[n]+d;
		for(long long i=1;i<=n;i++){
			long long l=i,r=n+1,res=i;
			while(l<=r){
				long long mid=(l+r)/2;
//				cout<<i<<" "<<l<<" "<<r<<" "<<mid<<" "<<a[mid]-a[i]<<'\n';
				if(a[mid]-a[i]<=d)res=mid,l=mid+1;
				else r=mid-1;
			}
			pos[i]=res;
//			cout<<"pos["<<i<<"]="<<pos[i]<<'\n';
		}
		pos[n+1]=n+1;
		if(c<=10){
			for(long long i=1;i<=n;i++){
				for(long long j=1;j<=n;j++){
					dis[i][j]=2e18,cnt[i][j]=1;
				}
			}
			for(long long i=1;i<=n;i++)bfs(i);
			long long ans=0;
			for(long long i=1;i<=n;i++){
				for(long long j=i+1;j<=n;j++){
//					cout<<i<<" "<<j<<" "<<dis[i][j]<<" "<<cnt[i][j]<<'\n';
					ans+=cnt[i][j]==2;
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		if(c>=11&&c<=12){
			long long diff=a[2]-a[1],cj=d/diff,ans=0;
//			cout<<n<<" "<<d<<" "<<diff<<'\n';
			//i~i+cj
			for(long long i=1;i<=n;i++)ans+=i+2*cj-1<=n;
			if(cj<=1)ans=0;
			cout<<ans<<'\n';
			continue;
		}
		if(c>=13&&c<=14){
			long long mn=a[1]+d,mx=a[n]-d,p1,p2,ans=0,cnt=0;
			for(long long i=1;i<=n;i++){
				if(a[i]<=mn)p2=i;
			}
			for(long long i=n;i>=1;i--){
				if(a[i]>=mx)p1=i;
			}
			//p1~p2 can go any where
			//an-a1<=2d
			if(p2-p1>=2){
				cout<<0<<'\n';
				continue;
			}
			if(p2==p1+1){
				for(long long i=1;i<p1;i++){
					if(pos[i]!=p2)continue;
					ans+=n-pos[p1-1];
				}
				cout<<ans<<'\n';
				continue;
			}
			//p1==p2 so that the only one position can go anywhere is p1
			//a simple way is u->p1->v
			//have another way make u->v
			//1. u->p1-1->v      2.u->p1+1->v
			for(long long i=1;i<p1;i++){
//				cout<<"pos["<<i<<"]="<<pos[i]<<'\n';
				if(pos[i]>=p1+2)continue;
				if(pos[i]==p1+1){
					ans+=n-pos[p1-1];
					cout<<pos[p1-1]<<'\n';
					//if u->p1+1->v is ok,then u->p1-1->v must be can't go
				}
				else ans+=max(0ll,pos[p1-1]-pos[p1-2]);
				//now u->p1-1->v must be true
				//u->p1-2->v must be can't go
			}
			cout<<ans<<'\n';
			continue;
		}
		for(long long i=1;i<=n+1;i++){
			long long tmp=i;
			jp[i][0]=i;
//			cout<<i<<" "<<pos[i]<<'\n';
			for(long long j=1;j<=30;j++){
				tmp=pos[tmp];
				jp[i][j]=tmp;
			}
		}
		long long ans=0;
		for(long long i=1;i<=n;i++){
			for(long long j=2;j<=30;j++){
//				cout<<i<<" "<<j<<" "<<jp[i][j]<<'\n';
				if(jp[i][j]==n+1)break;
				long long cnt=0,mx=-1,mx2=-1;
				for(long long k=0;k<j;k++){
					//jump k full,1 times less 1,j-k-1 times full
					long long ps=jp[jp[i][k]-1][j-k];
//					cout<<"mid:"<<k<<" "<<jp[i][k]<<" "<<ps<<'\n';
					if(ps>mx)mx2=mx,mx=ps;
					else if(ps>mx2)mx2=ps;
				}
//				cout<<i<<" "<<j<<" "<<mx<<" "<<mx2<<'\n';
				if(mx!=-1&&mx2!=-1)ans+=mx-mx2;
			}
//			cout<<i<<" "<<ans<<'\n';
		}
		cout<<ans<<'\n';
		for(long long i=1;i<=n+1;i++){
			for(long long j=0;j<=30;j++){
				jp[i][j]=0;
			}
		}
	}
}
/*
13 1
8 10
1 2 3 10 11 12 13 15

15 1
5 3
-3 0 2 3 4
*/
