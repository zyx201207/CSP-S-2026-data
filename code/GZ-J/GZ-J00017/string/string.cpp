//GZ-J00017 贵阳市白云区华师一学校 闫宇凡 
#include<bits/stdc++.h>
using namespace std;
int n,cnt;
long long a[200005],ans,v;
char c[200005],x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&v);
		scanf("%s",&x);
		if(x!=c[cnt]){
			++cnt;
			c[cnt]=x;
		}
		a[cnt]+=v;
	}
	int l=1,r=cnt;
	while(l<r){
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
		}
		if(a[l]==a[r]){
			a[l]=0;
			a[r]=0;
			l++;
			r--;
		}
		else if(a[l]<a[r]){
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
		else{
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
	}
	printf("%lld",ans);
	return 0;
}
