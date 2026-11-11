#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500010],ans,sum1,maxn=-1,b[500010]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==i){
			sum1++;
		}
	}
	sort(a+1,a+n+1);
	if(sum1=n){
		for(int i=1;i<=n;i++){
			if(i*i-i==2*m){
				printf("%lld",i);
				return 0;
			}
			if(i*i-i>2*m){
				printf("%lld",(i-1));
				return 0;
			}
		}
	}
	int m1=m;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			b[j]=a[i]-a[j];
			if(m-b[j]>=0){
				ans++;
				m-=b[j];
			}
			else break;	
		}
		maxn=max(maxn,ans);
		ans=0;
		m=m1;
	}
	printf("%lld",maxn);
	return 0;
} 
