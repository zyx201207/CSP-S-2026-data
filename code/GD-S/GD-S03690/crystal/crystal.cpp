#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m,cnt,ans,t,su[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	t=m;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	if(n<=10000){
		sort(a+1,a+n+1);
		for(int i=n;i>=1;--i){
			cnt=1,t=m;
			for(int j=i-1;j>=1;--j){
				//cout<<a[i]<<" "<<a[j]<<endl;
				if(t>=a[i]-a[j]){
					t-=a[i]-a[j];
					++cnt;
				}else{
					break;
				}
			}
			ans=max(ans,cnt);
		}
		printf("%lld",ans);
	}else{
		ans=1,t=a[2]-a[1];
		for(int i=2;i<=n;++i){
			su[i]=su[i-1]+t*(i-1);
			if(m>=su[i]) ++ans;
		}
		printf("%lld",ans);
	}
	return 0;
} 
