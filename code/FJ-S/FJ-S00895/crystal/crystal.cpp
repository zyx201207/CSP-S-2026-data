#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*f;
}
#define N 500010
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	int ans=1,sum=0;
	for(int i=2,j=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-j);
		while(sum>m)sum-=a[i]-a[j++];
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
