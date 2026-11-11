#include<iostream>
#define int long long
using namespace std;
int _,n,d,x[2000005],l[2000005],r[2000005],lt[2000005],rt[2000005],ans,rec[100005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>_;
	cin>>_;
	for(int i=1;i<=_;++i){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i)l[i]=r[i]=lt[i]=rt[i]=0;
		l[1]=0;
		r[0]=1;
		for(int i=1;i<=n;++i)cin>>x[i];
		for(int l1=1,r1=1;l1<=n;++l1){
			while(r1<n&&x[r1+1]-x[l1]<=d)l[++r1]=l1;
			r[l1]=r1;
		}
		r[n]=n+1;
		l[n+1]=n;
		for(int i=2;i<=n;++i)if(l[i]<l[i+1])lt[i]=lt[l[i]]+l[i+1]-l[i];
		for(int i=n-1;i;--i)if(r[i-1]<r[i])rt[i]=rt[r[i]]+r[i]-r[i-1];
		for(int i=1;i<n;++i)if(r[i]>i+1&&l[i+1]<i)ans+=lt[i+1]*rt[i];
		cout<<ans<<"\n";
	}
}