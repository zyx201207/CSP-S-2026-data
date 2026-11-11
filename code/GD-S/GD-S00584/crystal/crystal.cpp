#include <bits/stdc++.h>
using namespace std;
long long BB,n,m,a[500055],b[500055],mx,ans,sum,j;
bool A=1,B=1,c,d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m>>a[1]>>a[2];
	if(a[2]!=2||a[1]!=1) A=0;
		BB=a[2]-a[1];
		for(int i=3;i<=n;i++){
			cin>>a[i];
			if(A&&a[i]!=i){
				A=0;
			}if(B&&a[i]-a[i-1]!=BB){
				B=0;
			} 
		}
	if(A){
		m=min(n,m+1);
		printf("%lld",m);
	}else if(B){
		m/=BB;
		m++;
		printf("%lld",m);
	}else{
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
		j=1;
		while(ans<=m&&j<=n) ans+=b[j++],sum++;
		ans-=b[--j],sum--;
		mx=max(mx,sum);
		for(int i=2;i+sum<=n;i++){
			ans-=b[i-1];
			ans+=b[i-1+sum];
			if(ans<=m){
				if(c){
					c=0,d=0;
					continue;
				}d=1;
				mx=max(mx,sum);
				ans+=b[i-1];
				sum++,i--;
			} 
			else{
				ans+=b[i-1];
				ans-=b[i-1+sum];
				sum--;
				if(d){
					d=0,c=0;
					continue;
				}i--,c=1;
			}
		}mx++;
		printf("%lld",mx);
	}
	return 0;
} 
