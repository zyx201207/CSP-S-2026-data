#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[233333],mpos,len,ans;
char c[233333];
int read(){
	int res=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;len+=a[i],a[i]=len,++i)
		a[i]=read(),c[i]=getchar();
	for(int i=1,sum=0;i<=n;++i){
		sum+=a[i]-a[i-1];
		if(sum>=len+1>>1){mpos=i;break;}
	}
	for(int i=1,j=n,l=1,r=len;i<=mpos&&j>=mpos;){
		int nl=a[i],nr=a[j-1]+1;
		ans+=(c[i]!=c[j]?min(nl-l+1,r-nr+1):0);
		if(nl-l+1<=r-nr+1){++i;r-=nl-l+1;l=nl+1;}
		if(nl-l+1>=r-nr+1){--j;l+=r-nr+1;r=nr-1;}
	}
	printf("%lld",ans);
	return 0;
}
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
