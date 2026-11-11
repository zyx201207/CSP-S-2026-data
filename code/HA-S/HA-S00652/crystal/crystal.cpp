#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){char ch=getchar();int f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}ll x=0;while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}return x*f;}
inline void write(ll x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int n;
ll m;
const int N=5e5+5;
ll a[N];
int ans;
ll now;int tot;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	a[n+1]=1e18;
	for(int i=1,l=1;i<=n;i++){
		now+=1ll*(a[i]-a[i-1])*(i-l);
		while(a[i]==a[i+1]){
			i++;
		}
		while(now>m&&l<i){
			now-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	write(ans);
	return 0;
}
