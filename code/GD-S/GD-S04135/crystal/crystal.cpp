#include<bits/stdc++.h>
using namespace std;
#define getc() (ss==tt&&(tt=(ss=In)+fread(In,1,1<<15,stdin)),ss==tt?EOF:*ss++)
char In[1<<15],*ss=In,*tt=In;
template<class T>
void read(T&x){
	char c=getc();bool f=1;x=0;
	for(;!isdigit(c);f^=(c=='-'),c=getc());
	for(;isdigit(c);x=(x<<3)+(x<<1)-(c^48),c=getc());
	x=f?-x:x;
}
typedef long long ll;
int n,ans;
ll m,a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=0,r=i;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-b[i]+b[mid-1]<=m) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-r);
	}
	cout<<ans;
	return 0;
}
