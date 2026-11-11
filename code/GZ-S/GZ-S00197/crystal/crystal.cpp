//GZ-S00197 盘州市第二中学 于雪晨 
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n;
	long long m;

	scanf("%d%lld",&n,&m);
	
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	
	sort(a+1,a+n+1);
	
	int q1=1;
	
	int ans=1;
	
	for(int i=2;i<=n;i++){
		
		if(b[i-1]+q1*(a[i]-a[i-1])<=m){
		
			b[i]=b[i-1]+q1*(a[i]-a[i-1]);
			
			q1++;
			
	}
		else q1=1;
		
		ans=max(ans,q1);
	}
	printf("%d",ans);
	return 0;
} 
