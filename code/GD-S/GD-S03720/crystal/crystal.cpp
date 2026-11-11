#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500010]{};
long long sum=0,ans=0;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		
	}
	a[0]=a[1];
	for(long long i=1;i<=n;i++){		
		a[i]=a[i+1]-a[i];		
		if(sum+a[i]*i<=m){
			sum+=a[i]*i;
		}
		else {
			ans=i;
			break;
		}
	}	
	printf("%lld",ans);	
	return 0;
} 
