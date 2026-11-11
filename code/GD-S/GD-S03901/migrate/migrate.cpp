#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,T;
int n,d;
int a[N];
int f[N];
int ok[N];
int st[N][24];
int diff[N];
int lg[N];
int query(int l,int r){
	int len=r-l+1;
	int k=lg[len];
	return max(st[l][k],st[r-(1<<k)+1][k]);
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	for(int i=2;i<=N-1;i++)lg[i]=lg[i>>1]+1;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i],f[i]=0,ok[i]=0,diff[i]=0;
		st[1][0]=0;
		for(int i=2;i<=n;i++){
			diff[i]=a[i]-a[i-1];
			st[i][0]=diff[i];
		}
		for(int j=1;j<=23;j++){
			for(int i=1;i+(1<<j)-1<=n;i++){
				st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			}
		}
		for(int i=4;i<=n;i++){
			ok[i]+=ok[i-1];
			if(a[i]-a[i-3]<=d)continue;
			if(a[i-2]-a[i-3]<=d&&a[i]-a[i-2]<=d&&a[i-1]-a[i-3]<=d&&a[i]-a[i-1]<=d){
				ok[i]++;
			}
		}
		for(int i=4;i<=n;i++){
			for(int j=1;j<i;j++){
				if(query(j+1,i)>d)continue;
				if(f[j]==0){
					if(i-j<3)continue;
					else{
						int cnt=ok[i]-ok[i-3];
						if(cnt==1)f[i]+=1;
					}
				}
				else if(f[j]!=0){
					if(i-j<3)f[i]+=f[j];
					else{
						int cnt=ok[i]-ok[i-3];
						if(cnt==0)f[i]+=f[j];
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)ans+=f[i];
		cout<<ans<<'\n'; 
	}
	return 0;
}
