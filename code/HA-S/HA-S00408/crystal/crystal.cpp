#include<bits/stdc++.h>
#define siz(_) ((int)_.size())
#define pb emplace_back
#define mk make_pair
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
const int N=5e5+5;
int n;
ll a[N],m,s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=0,r=i;
		ll x=a[i];
		while(l<r){
			int mid=(l+r)>>1;
			if(x*(i-mid)-(s[i]-s[mid])<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l);
	}
	printf("%d\n",ans);
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<"s"<<endl;
	return 0;
}
