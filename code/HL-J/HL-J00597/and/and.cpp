#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005];
int er(int x,int y){
	long long sum=0,xx=0,yy=0,xxx=x,yyy=y;
	while(xxx){
		xxx/=2;
		xx++;
	}
	while(yyy){
		yyy/=2;
		yy++;
	}
	if(xx>yy){
		for(long long i=1;i<=xx-yy;i++){
			x/=2;
		}
	}
	else{
		for(long long i=1;i<=yy-xx;i++){
			y/=2;
		} 
	}
	long long j=1;
	while(x){
		sum+=((x%2)&(y%2))*j;
		x/=2;
		y/=2;
		j*=2;
	}
	return sum;
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=-1;
	for(long long i=1;i<=n;i++){
		long long cnt=0;
		for(long long j=i;j<m+i-1;j++){
			cnt+=er(a[j],a[j+1]);
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
