#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
int C,T;
int n,d;
int a[maxn]; 
int cnt[maxn],dis[maxn];
int l[maxn],r[maxn],L[maxn],R[maxn];
inline void solve1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) dis[j]=1e9,cnt[j]=0;
		dis[i]=0;
		cnt[i]=1;
		for(int j=i;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[k]-a[j]>d) break;
				if(dis[k]<dis[j]+1) continue;
				dis[k]=dis[j]+1;
				cnt[k]+=cnt[j]; 
			}
		}
		for(int j=i;j<=n;j++) if(cnt[j]==2) ++ans;
	}
	cout<<ans<<'\n';
	return ;
}
inline void solve2(){
	int ans=0;
	for(int i=1;i<=n;i++){
		l[i]=r[i]=L[i]=R[i]=0;
		r[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
		l[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
	}//求出半径
	for(int i=1;i<=n;i++){
		int le=r[i]+1,ri=n,mid;
		while(le<=ri){
			mid=(le+ri)>>1;
			if(r[i]-l[mid]+1>1) R[i]=mid,le=mid+1;
			else ri=mid-1;
		}
		le=r[i]+1,ri=n;
		while(le<=ri){
			mid=(le+ri)>>1;
			if(r[i]-l[mid]+1<=2) L[i]=mid,ri=mid-1;
			else le=mid+1;
		}
		if(L[i]&&R[i]) ans+=R[i]-L[i]+1;
	}//求出first
	cout<<ans<<'\n';
	return ;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(C<=6) solve1();
		else if(C<=14) solve2();
	}
	return 0;
 } 
 /*
 0 1
 7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
