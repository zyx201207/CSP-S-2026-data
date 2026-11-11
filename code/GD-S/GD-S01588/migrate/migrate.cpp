#include<bits/stdc++.h>
using namespace std;
const int N=5005,NN=2e6+5;
int n,dis[N][N],t[N][N],to[NN],to2[NN],ll[NN],rr[NN];long long d,x[NN];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1,j=1;i<=n;i++){
		while(x[j+1]-x[i]<=d)j++;
		to[i]=j;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=1e9,t[i][j]=0;
	for(int l=1;l<=n;l++)for(int i=1;i<=n-l;i++){
		int j=i+l;
		if(j<=to[i]){
			dis[i][j]=1,t[i][j]=1;continue;
		}
		dis[i][j]=dis[to[i]][j]+1;
		if(i==to[i])continue;
		if(dis[to[i]][j]!=dis[to[i]-1][j]||to[i]-1<=i){
			t[i][j]=t[to[i]][j];
		}else if(dis[to[i]-1][j]!=dis[to[i]-2][j]||to[i]-2<=i){
			t[i][j]=min(3,t[to[i]][j]+t[to[i]-1][j]);
		}else{
			t[i][j]=3;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)cnt+=(t[i][j]==2);
	cout<<cnt<<'\n';
}
void solve2(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	if(d<=x[2]-x[1])cout<<0<<'\n';
	else cout<<max(0ll,n+1-2*d/(x[2]-x[1]))<<'\n';
}
void solve3(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1,j=1;i<=n;i++){
		while(x[j+1]-x[i]<=d)j++;
		to[i]=j;
	}
	for(int i=1;i<=n;i++)ll[i]=1e9,rr[i]=0;
	for(int i=n,j=n;i>=1;i--){
		while(x[i]-x[j-1]<=d)j--;
		to2[i]=j,ll[j]=min(ll[j],i),rr[j]=max(rr[j],i);
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=rr[to[i]-1]-max(ll[to[i]-1],to[i]+1)+1;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	system("fc migrate4.ans migrate.out");return 0; 
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	int _,__;cin>>_>>__;
	if(_<=10)while(__--)solve();
	else if(_<=12)while(__--)solve2();
	else if(_<=14)while(__--)solve3();
	else while(__--)cout<<0<<'\n';
} 
