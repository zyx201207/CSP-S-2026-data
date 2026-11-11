#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+1;
int n,a[N],m,ans,b[N];
int cmp(int x,int y){
	return x<y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		int hz[N],y=1,x=i;
		while(x<=n){
			hz[x+1]=N;
			for(int j=y;j<=x;j++)hz[j]=hz[j-1]+a[j];
			for(int j=y;j<=x;j++)hz[x+1]=min(hz[x+1],a[j]-hz[j-1]);
			if(hz[x+1]<=m)b[i]=max(b[i],hz[x+1]);
			for(int j=y;j<=x+1;j++)hz[j]=0;
			y++;
			x++;
		}
		if(b[i]>=b[i-1])ans=i;
	}
	cout<<ans;
}
