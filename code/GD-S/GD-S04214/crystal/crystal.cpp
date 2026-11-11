#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],res[500005],d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	bool flag1=true;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==2)d=a[2]-a[1];
		if(i>2 && a[i]-a[i-1]!=d)flag1=false;
	}
	int l=0,r=n;
	if(flag1){
		long long now=2*m;
		while(l<r){
			int mid=(l+r)>>1;
			if(d*mid*(mid-1)<=now){
				ans=mid;
				l=mid+1;
			}else r=mid;
		}
		printf("%d\n",ans);
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)res[i]=a[i]+res[i-1];
	while(l<r){
		int mid=(l+r)>>1;
		bool flag=false;
		for(int i=mid;i<=n;i++){
			int j=i-mid+1;
			long long now=a[i]*mid-(res[i]-res[j-1]);
			if(now<=m){
				flag=true;
				break;
			}
		}
		if(flag){
			ans=mid;
			l=mid+1;
		}else r=mid;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
