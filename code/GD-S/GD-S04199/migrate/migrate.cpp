#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
ll nxt[N][21],n,d;
ll a[N],R[N],cnt[N];
ll dis[5010][5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			int pos=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
			nxt[i][0]=(pos==i?n+1:pos);
		//	cout<<"i="<<i<<" pos="<<pos<<"\n";
		}
		for(int j=1;j<=13;j++){
			nxt[n+1][j-1]=n+1;
			for(int i=1;i<=n;i++)nxt[i][j]=nxt[nxt[i][j-1]][j-1];
		//	if(j<=13){
		//		for(int i=1;i<=n;i++)cout<<"nxt["<<i<<"]["<<j<<"]="<<nxt[i][j]<<" ";
		//		cout<<"\n";
		//	}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dis[i][j]=0;
				int x=i;
				for(int k=12;k>=0;k--){
					if(nxt[x][k]<=j&&nxt[x][k-1]!=nxt[x][k]){
						x=nxt[x][k];
						dis[i][j]+=(1<<k);
					}	
				}
				if(x<j&&a[x]+d<a[j])dis[i][j]=0;
				if(x<j&&a[x]+d>=a[j])dis[i][j]++;
			//	cout<<"i="<<i<<" j="<<j<<" x="<<x<<" dis["<<i<<"]["<<j<<"]="<<dis[i][j]<<"\n";
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
			//	cout<<"dis["<<i<<"]["<<j<<"]="<<dis[i][j]<<"\n";
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				int cnt=0,d=dis[i][j];
				if(!d)continue;
				vector<int> vec;
				vec.clear();
				for(int k=i+1;k<=j-1;k++){
					if(a[k-1]+d>=a[k]&&a[k-1]+d<a[k+1])vec.push_back(k);
				}
				vec.push_back(i);
		//		cout<<vec.size()<<"\n";
				vec.push_back(j);
				for(int k=0;k<(int)vec.size()-1;k++){
					for(int l=vec[k]+1;l<=vec[k+1]-1;l++){
						if(dis[i][l]+dis[l][j]==d&&dis[i][l]&&dis[l][j])cnt++;
					}
				}
				if(cnt==2){
			//		cout<<"i="<<i<<" j="<<j<<"\n";
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
5 3
-3 0 2 3 4

*/
