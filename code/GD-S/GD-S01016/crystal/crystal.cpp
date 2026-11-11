#include<bits/stdc++.h>
using namespace std;
#define int long long
#define File(x) (freopen(x".in","r",stdin),freopen(x".out","w",stdout))
inline int read(){char ch=getchar();int f=1,x=0;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();return f*x;}
const int N=5e5+5;
int n,m,ans;
int a[N],sum[N];
signed main(){
	File("crystal");
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-sum[i]+sum[mid-1]<=m)ans=max(ans,i-mid+1),r=mid-1;
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}