#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+16;
int n,m,a[N],b[N],ans;
bool check(int l,int r,int x){
	if(l<1)return false;
	int tem=(r-l+1)*x-(b[r]-b[l-1]);
	return tem<=m;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int p=1,res=0;
		while(p){
			if(check(i-(res+p)+1,i,a[i]))res+=p,p<<=1;
			else p>>=1;
		}
		ans=max(ans,res);
	}
	cout<<ans<<"\n";
	return 0;
}
