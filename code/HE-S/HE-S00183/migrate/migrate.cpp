#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e3+5;
int a[N],lst[N],n,d;
int find(int i){
	int l=i,r=n,ans=i;
	while (l<=r){
		int mid=(l+r)/2;
		if (a[mid]<=a[i]+d)l=mid+1,ans=mid;
		else r=mid-1;
	}
	return ans;
}
int f[N][N];
void solve(){
	memset(a,0,sizeof a);
	memset(lst,0,sizeof lst);
	cin>>n>>d;
	for (int i=1;i<=n;++i)cin>>a[i];
	for (int i=1;i<=n;++i)lst[i]=find(i);
	memset(f,0x3f,sizeof f);
	for (int i=1;i<=n;++i){
		for (int j=i+1;j<=n;++j){
			if (a[j]-a[i]<=d)f[i][j]=1;
		}
	}
	for (int k=1;k<=n;++k){
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}

	}
	int ans=0;
	for (int i=1;i<=n;++i){
		for (int j=i+1;j<=n;++j){
			if (f[i][j]>5*n)break;
			int k=lst[i];
			bool ok1=0,ok2=1;
			while (k<j){
				int cnt=0;
				cnt+=(k-1>i&&f[k-1][j]==f[k][j]?1:0)+(k-2>i&&f[k-1][j]==f[k][j]?1:0);
				if (cnt==1&&ok1==0)ok1=1;
				else if ((cnt==1&&ok1)||cnt>=2)ok2=0;
				k=lst[k];
			}
			if (ok1&&ok2)ans++; 
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while (t--)solve();
}

//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
