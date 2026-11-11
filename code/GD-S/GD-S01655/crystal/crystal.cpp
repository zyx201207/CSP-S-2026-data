#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],sum[N];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){ x=x*10+(ch-'0'); ch=getchar();}
	return x*f;
}
void solve(){
	int n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		a[i]=abs(a[i+1]-a[i]);
	}
	sum[0]=0;
	int ans=1,num=1;
	for(int i=1;i<=n-1;i++){
		sum[i]=sum[i-1]+i*a[i];
		if(a[i]==0){
			num++;
		}else{
			ans=max(ans,num);
			num=1; 
		}
	}
	ans=max(ans,num);
	for(int i=1,j;i<=n-1;i++){
		for(j=i;j<=n-1;j++){
			if(sum[j]-sum[i]>m) break;
		}
		ans=max(ans,j-i+1);
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}	
