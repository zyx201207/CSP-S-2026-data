#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
namespace FastIO{
	inline ll read(){
		ll s=0,f=1;char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-')f=-1;
			c=getchar();
		}while('0'<=c&&c<='9'){
			s=(s<<1)+(s<<3)+c-'0';
			c=getchar();
		}return s*f;
	}
}
using FastIO::read;

const int N = 500050;
ll n,m;
ll a[N],b[N];
ll costsm;
int ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)b[i]=a[i]-a[i-1];
	for(int i=1,j=1;i<=n;i++){
		//j<=i always
		costsm+=(i-j)*b[i];
		while(costsm>m){
			costsm-=(a[i]-a[j]);
			j++;
		}
		ans=max(i-j+1,ans);
	}
	cout<<ans;
	
	
	
	return 0;
}
