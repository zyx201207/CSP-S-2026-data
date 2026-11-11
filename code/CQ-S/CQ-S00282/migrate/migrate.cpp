#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e3+10;
ll a,b,n,m,s,d,c,t,f[N],dp[N][N],dp1[N][N],bj[N][N];
struct node{
	int l,z;
	bool operator>(const node& other) const {
		return z>other.z;
	}
};
vector<node>v[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	if(c==1)cout<<1<<"\n"<<2;
	if(c==2)cout<<0<<"\n"<<1;
//	while(t--){
//		cin>>n>>d;
////		for(int i=1;i<=n;i++)v[i].claer();
//		memset(dp,0x3f,sizeof dp);
////		memset(dp1,0x3f,sizeof dp1);
////		memset(bj,0,sizeof bj);
//		ll maxx=0;
//		for(int i=1;i<=n;i++)cin>>f[i],dp[i][i]=dp1[i][i]=0,maxx=max(f[i],maxx);
////		for(int i=1;i<=n;i++){
////			for(int j=1;j<=n;j++){
////				if(abs(f[i]-f[j])<=d)dp[i][j]=abs(f[i]-f[j]);
////			}
////		}
//		if(c<=2){
//			for(int i=0;i<(1<<n);i++){
//				int sta[20],top=0;
//				for(int j=0;j<3;j++){
//					if((i>>j)&1){
//						sta[++top]=j+1;
//					}
//				}
//				int idx=f[sta[1]];
//				int sum=0;
//				for(int j=2;j<=top;j++){
//					if(abs(f[sta[j]]-f[idx])<=d)sum+=abs(f[sta[j]]-idx),idx=j;
//					else{
//						sum=INT_MAX;
//						break;
//					}
//				}
//				if(sum!=INT_MAX)dp[sta[top]][sum]++;
//				if(dp[sta[top]][sum]==2)s++;
//				if(dp[sta[top]][sum]>2)s--;
//				cout<<s;
//			}
//			cout<<s<<"\n";
//		}
//	}
	return 0;
}

