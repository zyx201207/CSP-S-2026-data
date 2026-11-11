//GZ-S00016 贵阳市白云区华师一学校 闫宇凡 
#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],x,s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	bool d=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	x=a[2]-a[1];
	s[1]=0;
	s[2]=s[1]+(a[2]-a[1]);
	for(int i=3;i<=n;i++){
		s[i]=s[i-1]+(a[i]-a[i-1]);
		if(a[i]-a[i-1]!=x){
			d=0;
		}
	}
	if(d){
		for(int i=n;i>=1;i--){
			if(1ll*((i-1)*(i)*x/2)<=m){
				printf("%d",i);
				break;
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<r){
			int mid=(l+r+1)/2;
			if(s[mid]-s[i]<=m){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,l-i+1);
	}
	printf("%d",ans);
	return 0;
}
