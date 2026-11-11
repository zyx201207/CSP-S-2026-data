#include<bits/stdc++.h>
#define int long long
#define N 2000010
using namespace std;
int c,T,n,d,x[N],h[N],sum[N];
struct node{
	int u,cnt;
};
node tmp[N];
queue<node>q;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==1){
			cout<<"0\n";
			continue;
		}
		bool flag=true;
		for(int i=1;i<n-1;i++){
			if(x[i+1]-x[i]!=x[i+2]-x[i+1]){
				flag=false;
				break;
			}
		}
		if(flag){
			d/=(x[2]-x[1]);
			if(d<=1){
				cout<<"0\n";
				continue;
			}
			if(d*2<=n){
				cout<<n+1-d*2<<"\n";
			}else{
				cout<<"0\n";
			}
			continue;
		}
		/*if(x[n]-x[1]<=10*d){
			for(int i=1;i<n;i++){
				//
			}
			continue;
		}*/
		for(int i=1;i<=n;i++){
			int l=i,r=n,best;
			while(l<=r){
				int mid=(l+r)/2;
				if(x[mid]-x[i]<=d){
					best=mid,l=mid+1;
				}else{
					r=mid-1;
				}
			}
			h[i]=best;
		}
		int ans=0;
		for(int i=1;i<n;i++){
			while(q.size()){
				q.pop();
			}
			for(int j=1;j<=n+1;j++){
				sum[j]=0;
			}
			q.push((node){i,1});
			while(q.size()){
				int tot=0,mx=0;
				while(q.size()){
					tmp[++tot]=q.front();
					mx=max(mx,q.front().u);
					q.pop();
				}
				int now=0;
				for(int j=1;j<=tot;j++){
					int u=tmp[j].u;
					int w=h[u];
					if(w>mx){
						sum[w]+=tmp[j].cnt;
						now=max(now,w);
					}
				}
				if(!now){
					break;
				}
				for(int j=now;j>mx;j--){
					sum[j]=min(sum[j]+sum[j+1],3LL);
					if(sum[j]==2){
						ans++;
					}
					q.push((node){j,sum[j]});
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}