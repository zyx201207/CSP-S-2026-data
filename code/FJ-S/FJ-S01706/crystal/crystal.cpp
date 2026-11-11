#include<bits/stdc++.h>
using namespace std;
#define int long long
void dd(int &ss){
	ss=0;
	char ch=getchar();int ff=1;
	while(ch<'0'||ch>'9'){if(ch=='-')ff=-1;ch=getchar();}
	while('0'<=ch&&ch<='9')ss=ss*10+ch-'0',ch=getchar();
	ss*=ff;
}
const int N=1e6+5;
int n,m;
int a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	dd(n),dd(m);
	for(int i=1;i<=n;++i)dd(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	int l=1,ans=1;
	for(int r=1;r<=n;++r){
		while(l<r&&(r-l+1)*a[r]>m+sum[r]-sum[l-1])
			++l;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
