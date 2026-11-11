#include<bits/stdc++.h>
using namespace std;

const int N=5e5+40;

int n;
long long m,a[N],ans;


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	long long p1=1,p2=1,nowm=0;
	while(p1<=p2&&p1<=n&&p2<=n){
		if(nowm<=m){
			p2++,nowm+=(a[p2]-a[p2-1])*(p2-p1);
			if(nowm>m){
				nowm-=(a[p2]-a[p2-1])*(p2-p1),p2--;
				p1++,nowm-=a[p2]-a[p1-1];
			}
			ans=max(ans,p2-p1+1);
		}else{
			p1++,nowm-=a[p2]-a[p1-1];
			ans=max(ans,p2-p1+1);
		}
		//printf("%d %d %d\n",p1,p2,nowm);
	}
	printf("%lld\n",ans);
	return 0;
}
