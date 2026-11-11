#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int n,m,a[N],ans,l=0x3f3f3f3f3f3f3f3f,r=-0x3f3f3f3f3f3f3f3f;
bool ff=1;
int js(int p,int q){
	int ret=0;
	for(int i=q-1;i>=p;i--)	ret+=a[q]-a[i];
	return ret;
}
int check(int x){
	int l=1,r=x,mid;
	while(l<r){
		mid=(l+r)>>1;
		int y=js(mid,x);
		if(y<=m)	r=mid;
		else	l=mid+1;
	}
	return x-r+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+1+n);
		if(a[1]<0){
			int add=0-a[1];
			for(int i=1;i<=n;i++)	a[i]+=add;
		}
		for(int i=1;i<=n;i++){
			if(ans<check(i)){
				ans=check(i);
			}
		}
		printf("%lld",ans);
	}else{
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(a[i]!=i)	ff=0;
		}
		if(ff==1){
			ans=1;
			int t=1;
			while(m>=t){
				m-=t;
				ans++;
				t++;
				if(ans==n)	break;
			}
			printf("%lld",ans);
		}else{
			ans=1;
			sort(a+1,a+1+n);
			int t=a[2]-a[1];
			while(m>=t){
				m-=t;
				ans++;
				t+=a[2]-a[1];
				if(ans==n)	break;
			}
		}
	}
	return 0;
}
