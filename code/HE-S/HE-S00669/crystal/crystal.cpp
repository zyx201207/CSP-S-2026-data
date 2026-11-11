#include<bits/stdc++.h>
using namespace std;
long long n,m,yyn,cnt=0;
long long a[100000000],b[100000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		yyn=i;
		for(int j=1;j<=m;j++){
			if(a[yyn-1]<a[yyn]){
				a[yyn-1]+=1;
			}
			else{
				yyn-=1;
				if(a[yyn-1]<a[yyn]){
				a[yyn-1]+=1;
			}
			}
		}
	for(int h=1;h<=n;h++){
		if(a[h]==a[i])
			b[i]+=1;
		}
	}
	sort(b+1,b+n+1);
	printf("%lld\n",b[n]);
	return 0;
} 
