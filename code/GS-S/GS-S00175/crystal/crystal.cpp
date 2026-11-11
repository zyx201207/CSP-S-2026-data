#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,b[500005],c[500005],sum=0,k,ans=-1,w=1;
bool cmp(long long x,long long y){
	return x<y;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		c[i]=c[i-1]+b[i]*i;
	}
	b[n]=0;
	c[n]=0;
	for(int i=1;i<n;i++){
		sum+=b[i]*(i-k);
		if(sum<=m){
			w=i-k+1;
			ans=max(ans,w);
		}else{
			for(int j=k+1;j<=i;j++){
				sum-=a[i+1]-a[j];
				if(sum<=m){
					k=j;
					break;
				}
			}
			w=i-k+1;
			ans=max(ans,w);
		}
	}
	cout<<ans;
	return 0;
} 
