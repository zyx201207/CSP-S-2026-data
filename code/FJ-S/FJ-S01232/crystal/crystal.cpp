#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,sum,ans,a[N],b[N],c[N],cnt[N],pre[N];
ll read(){
	char ch;ll s=0,w=1;
	while((ch=getchar())>'9' || ch<'0') if(ch=='-') w=-1;
	while(ch>='0' && ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	b[++sum]=a[1];
	cnt[sum]++;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]) b[++sum]=a[i];
		cnt[sum]++;
	}
	for(int i=1;i<=sum;i++){
		c[i]=c[i-1]+b[i]*cnt[i];
		pre[i]=pre[i-1]+cnt[i];
	}
	ans=cnt[1];
	for(int i=2;i<=sum;i++){
		ll l=1,r=i-1,idx=0;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(m>=b[i]*(pre[i-1]-pre[mid-1])-(c[i-1]-c[mid-1])){
				idx=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		if(idx==0){
			ans=max(ans,cnt[i]+m/(b[i]-b[i-1]));
		}
		else{
			if(idx==1){
				ans=max(ans,pre[i]);
			}
			else{
				ll w=b[i]*(pre[i-1]-pre[idx-1])-(c[i-1]-c[idx-1]);
				ll diff=b[i]-b[idx-1];
				ans=max(ans,(m-w)/diff+pre[i]-pre[idx-1]);
			}
		}
	}
	cout<<ans;
	return 0;
}
