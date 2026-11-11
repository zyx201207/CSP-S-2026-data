//GZ-S00026 张蔚远 贵阳白云区华师一学校 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	if(a[1]+m<a[2]){
		cout<<0;
		return 0;
	}
	long long ans=1,m1=m;
	for(int i=2;i<=n;i++){
		m1=m1-((a[i]-a[i-1])*ans);
		if(m1>=0&&i!=2){
			ans++;
		}
		
		if(m1<=0){
			break;
		}
	}
	printf("%lld",ans+1);
	return 0;
} 
