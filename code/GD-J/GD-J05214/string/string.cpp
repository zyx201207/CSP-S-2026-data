#include<bits/stdc++.h>
using namespace std;
long long n;
char c[2010];
long long len=0;
long long ans=0;
struct node{
	long long s,e;
};
node a[200100];
long long findnum(long long x)
{
	for(int i=1;i<=n;i++){
		if(x>=a[i].s and x<=a[i].e) return i;
	}
}
void find(long long l,long long r,char x)
{
	long long ll,rr;
	rr=len-l+1;
	ll=len-r+1;
	for(long long i=ll;i<=rr;){
		int num=findnum(i);
		if(c[num]!=x){
			if(a[num].e<=rr){
				ans+=a[num].e-i+1;
			}else{
				ans+=rr-i+1;
				return;
			}
		}
		i=a[num].e+1;
	}
	return;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long x;
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		cin>>c[i];
		a[i].s=len+1;
		len+=x;
		a[i].e=len;
	}
	long long mid=len>>1;
	for(long long i=1;i<=mid;){
		int num=findnum(i);
		if(a[num].e<=mid){
			find(i,a[num].e,c[num]);
		}else{
			find(i,len-a[num].e,c[num]);
			printf("%lld",ans);
			return 0;
		}
		i=a[num].e+1;
	}
	printf("%lld",ans);
}
