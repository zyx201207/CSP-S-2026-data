#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9' || ch<'0'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return s*w;
}
int n,m,a[N],sum[N];
int f(int x){
	int pos=upper_bound(a+1,a+1+n,x)-a-1,l=1,r=pos,ans=-1;
	while(l<=r){
		int mid=l+r>>1,tmp=(pos-mid+1)*x-sum[pos]+sum[mid-1];
		if(tmp<=m) ans=mid,r=mid-1;
		else l=mid+1; 
	}
	if(ans==-1) return 0;
	return pos-ans+1;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		ans=max(ans,f(a[i]));
	}
	cout<< ans;
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
