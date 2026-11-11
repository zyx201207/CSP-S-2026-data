#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,k,a[N],b[N],ans;
int read(){
	char ch=getchar();
	int x=0,y=1,cnt=5;
	while(ch<'0'||ch>'9'){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'&&cnt){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	for(int i=n;i>1;i--)
		a[i]-=a[i-1];
	a[1]=0;
	for(int i=2;i<=n;i++)
		b[i]=a[i]+b[i-1];
	int l=n,r=n;
	while(r>1&&l>=1){
		if(a[l]+a[r]+b[r]-b[l]<=k){
			ans=max(ans,r-l+1),l--;
		}else r--;
	}
	printf("%lld",ans);
	return 0;
}
