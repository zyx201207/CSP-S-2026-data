#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int ans=0,f=1;
	while(c<48||c>57) (c==45?f=-1:1),c=getchar();
	while(c>=48&&c<=57) ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return ans*f;
} 
const int N=5e5+10;
int n,m,a[N],s[N];
main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1); 
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int mx=1;
	for (int i=1;i<=n;i++){
		int l=1,r=i,pos=i;
		while(l<=r){
			int mid=l+r>>1;
			if ((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m) pos=mid,r=mid-1;
			else l=mid+1;
		}
		mx=max(mx,i-pos+1);
	}
	cout <<mx<<endl;
	return 0;
}
