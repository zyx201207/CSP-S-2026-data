#include <bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,f=1; char h=getchar();
	while(!isdigit(h)){if(h=='-') f=-f; h=getchar();}
	while(isdigit(h)){x=(x<<3)+(x<<1)+(h^48); h=getchar();}
	return x*f;
}
const int N=5e5+10;
int n,m,ans,a[N],pre[N];
bool check(int i,int len){
	int j=i-len+1;
	if(a[i]*len-(pre[i]-pre[j-1])<=m) return 1;
	return 0;
}
signed main(){
//	freopen("D:/csps-new/down/crystal/crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(i,mid)) res=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
ÎÒÌ«Å£±ÆÁË£¬15minÄÃÏÂ100pts 
*/
