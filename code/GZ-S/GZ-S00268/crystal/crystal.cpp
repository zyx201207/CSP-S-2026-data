//GZ-S00268 遵义天立学校 杨润凯 
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
typedef long long ll;
int n;
ll m,a[maxn],d[maxn];
int ans;
ll mn=1e5+5,mx=-1e5-5;
void rink(int x){
	for(int i=1;i<=n;++i)d[i]=abs(x-a[i]);
	sort(d+1,d+n+1);
	int cnt=1,res=m,sum=0;
	while(res>=d[cnt]&&cnt<=n){
		res-=d[cnt];
		++cnt,++sum;
	}
	ans=max(ans,sum);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);

	for(int i=1;i<=n;++i){
	    scanf("%lld",&a[i]);
	    mx=max(mx,a[i]),mn=min(mn,a[i]);
	}
	if(n>=5e5){
//		printf("%d\n",n);
        int mid=n/2,cnt=1,d=a[mid]-a[mid-1];
        if(n%2){
        	mid+=1;
        	for(int i=1;i<=mid;++i){
        		if(m<i*d)break;
        		if(m>=i*d)++cnt,m-=i*d;
        		if(m>=i*d)++cnt,m-=i*d;
			}
		}else {
			for(int i=1;i<mid;++i){
        		if(m<i*d)break;
        		if(m>=i*d)++cnt,m-=i*d;
        		if(m>=i*d)++cnt,m-=i*d;				
			}
			if(m>=mid*d)++cnt;
		}
        printf("%d\n",cnt);
		return 0;
	}
	for(int i=mn;i<=mx;++i)rink(i);
	printf("%d\n",ans);
	return 0;
}
//5 5
//1 2 4 8 9

