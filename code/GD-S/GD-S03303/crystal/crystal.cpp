#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],c[N],e=0,ans=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i==1||a[i]!=a[i-1])b[++e]=a[i],c[e]=1;
		else c[e]++;
	}
	memset(a,0,sizeof(a));
	for(int i=1;i<e;i++)a[i]=b[i+1]-b[i];
	for(int j=1;j<=e;j++){
		int s=c[j],i=j-1,t=m,o=0;
		while(i>=1&&t>0){o+=a[i];
			if(t<o*c[i])s+=t/o,t=0;
			else t-=o*c[i],s+=c[i];
			i--;
		}
		ans=max(s,ans);
	}
	cout<<ans;
	return 0;
}
