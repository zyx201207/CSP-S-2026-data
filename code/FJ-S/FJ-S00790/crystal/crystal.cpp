#include<bits/stdc++.h>
using namespace std;
#define N 500010
int n,l=1,r;
long long m,a[N];
bool cmp(long long w,long long h)
{
	return w<h;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	r=n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)a[i]+=a[i-1];
	while(l<r){
		int mid=(l+r+1)>>1;
		bool flag=0;
		for(int i=mid;i<=n;i++){
			if((a[i]-a[i-1])*mid-(a[i]-a[i-mid])<=m){
				l=mid;
				flag=1;
				break;
			}
		}if(flag)continue;
		r=mid-1;
	}
	printf("%d",l);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
