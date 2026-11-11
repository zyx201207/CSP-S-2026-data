#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long m;
long long a[500006],s[500006];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=1,r=i;
		while(l<r){
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m)r=mid;
			else l=mid+1;
		}
//		printf("%d %d\n",i,l);
		ans=max(ans,i-l+1); 
	}
	printf("%d",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
*/
