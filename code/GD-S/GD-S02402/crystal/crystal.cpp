#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1;
long long s;
bool x=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=n;i>1;i--){
		a[i]-=a[i-1];
		if(a[i]!=a[n]){
			x=false;
		}
	}
	a[1]=0;
	if(x){
		m/=a[2];
		ans=0;
		s=0;
		while(m>=s){
			ans++;
			s+=ans;
		}
		printf("%lld\n",ans);
	}else{
		for(int i=2;i<=n;i++){
			a[i]+=a[i-1];
		}
		for(int i=1;i<n;i++){
			x=false;
			for(int j=1;j<=n-i;j++){
				s=0;
				for(int k=j+1;k<=j+i;k++){
					s+=(a[k]-a[k-1])*(k-j);
				}
				if(m>=s){
					ans=i+1;
					x=!x;
					break;
				}
			}
			if(!x){
				break;
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
