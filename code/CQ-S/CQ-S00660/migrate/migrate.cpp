#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define D long double
#define N 2000006
ll x[N];
int to[N],n;ll d;
int f[5003][5003];
int val[N],g[N];int id,T;
inline void solve(){
	cin>>n>>d;x[n+1]=4e18;
	for(int i=1;i<=n;i++)	cin>>x[i];
	int pos=1;
	for(int i=1;i<=n;i++){
		while((x[pos+1]-x[i])<=d)	pos++;
		to[i]=pos;
	}
	if(n<=5000){//暴力 
		int ans=0;
		/*for(int i=1;i<=n;i++)if(to[i]>i){
			vector<int> p;p.push_back(i);
			int pos=i;
			for(int j=i;j<=n;j++){
				if(pos==i){//前面没有东西 
					f[i][j]=0;
				}else{
					if(to[pos-1]>=j){//危险 
						if((pos-2>=i)&&(to[pos-2]>=j)){
							f[i][j]=2;
						}else{
							int tp=p[p.size()-2];
							if((tp!=i)&&(to[tp-1]>=pos-1)){
								//cerr<<"chk2: "<<i<<" "<<j<<endl;
								f[i][j]=2;
							}else{
								f[i][j]=f[i][tp]+1;
							}
						}
					}else{//取决于pos前面那个 
						f[i][j]=f[i][p[p.size()-2]];
					}
				}
				if(f[i][j]==1)	ans++;
				if(to[pos]==j)	pos=to[pos],p.push_back(pos);
				if(pos==to[pos])	break;//到不了下一个了 
			}
		}*/
		for(int i=1;i<=n;i++){
			val[i]=0;g[i]=1;queue<int> q;
			for(int j=i+1;j<=n;j++)	val[j]=1e9,g[j]=0;
			q.push(i);
			while(q.size()){
				int x=q.front();q.pop();
				for(int t=x+1;t<=to[x];t++){
					if(val[t]>val[x]+1){
						val[t]=val[x]+1;g[t]=g[x];
					}else if(val[t]==val[x]+1){
						g[t]+=g[x];g[t]=min(g[t],(int)(1e9));
					}
					if(t==x+1)	q.push(t);
				}
			}
			for(int i=1;i<=n;i++)	ans+=(g[i]==2);
		}
		cout<<ans<<"\n";return;
	}
	ll ans=0;//性质B 
	for(int i=1;i<=n;i++){
		int p=to[i];
		if(i+2>=p)	continue;
		int p1=to[p-2],p2=to[p-1];
		ans+=p2-p1;
	} 
	cout<<ans<<"\n";
}
inline void cln(){
	;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>id>>T;
	while(T--)	solve(),cln();
	return 0;
}
/*
0 1
5 2
1 2 3 4 5
*/
