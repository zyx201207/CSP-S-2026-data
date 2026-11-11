#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=5e5+9;
ll n,m,a[maxn],sum,ans=1;
ll read(){
	ll sum=0,ch=getchar(),g=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-') g=-1;	
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return sum*g;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(ll i=2,j=1;i<=n;i++){
		sum+=(i-j)*(a[i]-a[i-1]);
		//cout<<i<<' '<<j<<' '<<sum<<endl;
		while(sum>m){
			sum-=a[i]-a[j++];
		}
		//cout<<i<<' '<<j<<' '<<sum<<' '<<a[i]<<endl;
		ans=max(ans,i-j+1);
	}
	printf("%lld",ans);
	return 0;
}