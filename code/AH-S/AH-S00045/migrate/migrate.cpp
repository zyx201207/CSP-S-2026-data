#include<bits/stdc++.h>
using namespace std;
long long n,m,d,a[200002],c,t,sum=0,minp;
int jk(long long j,long long k,long long y){
	if(y>minp)return 0;	
	if(a[k]-a[k-1]>m||k==j)return 1;
	if(a[k]-a[k-1]>m)return 1;
	int x=0;
	for(int i=k-1;i>=j;i--){
		if(a[k]-a[i]>m)break;
		x+=jk(j,i,y+1);
	}
	return x;
}
void jj(long long j,long long k,long long y){
	if(a[k]-a[k-1]>m||k==j)minp=min(minp,y);
	if(a[k]-a[k-1]>m)minp=min(minp,y);
	for(long long i=k-1;i>=j;i--){
		if(a[k]-a[i]>m)break;
		jj(j,i,y+1);
	}
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(long long i=1;i<=t;i++){
		cin>>n>>m;
		sum=0;
		memset(a,0,sizeof(a));
		for(long long j=1;j<=n;j++)cin>>a[j];
		for(long long j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				minp=1e18*2+1;
				jj(j,k,1);
				if(jk(j,k,1)==2)sum++;
			}
		}
		cout<<sum<<endl;	
	}
    return 0;
}
