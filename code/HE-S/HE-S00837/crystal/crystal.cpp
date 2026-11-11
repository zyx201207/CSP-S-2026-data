#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#define in inline
#define int long long
#define did printf("---\n");
#define N 500005
using namespace std;
in int rd(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c^'0');
		c=getchar();
	}
	return x*f;
}
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd(),m=rd();
	bool ise=true,fa=true;
	for(int i=1;i<=n;i++){
		a[i]=rd();
		if(a[i]!=i)fa=false;
	}
	if(fa){
		int ans=1;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt+1<=m)cnt+=i,ans++;
			else break;
		}
		printf("%lld",ans);
		return 0;
	}
	sort(a+1,a+1+n);
	int c=m,ans=-1,cnt=0;
	for(int i=1;i<=n&&ise;i++){
		c=m,cnt=1;
		for(int j=i-1,h;j>=1;j--){
			h=a[i]-a[j];
			if(h>m){
				ise=false;
				break;
			}
			if(h>c){
				break;
			}
			c-=h;
			cnt++;
			//printf("i:%lld j:%lld a[i]:%lld a[j]:%lld c:%lld h:%lld cnt:%lld\n",i,j,a[i],a[j],c,h,cnt);
		}
		ans=max(ans,cnt);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
