#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],n,m,b[N];
long long check(long long q){
	long long sum=0,ct=0;
	for(int i=q;i>=1;i--){
		if(sum+(a[q]-a[i])>m)break;
		else{
			sum+=(a[q]-a[i]);
			ct++;
		}
	}
	return ct;
}
//long long er(){
//	long long L=1,R=n,mid;
//	while(L<=R){
//	cout<<mid<<' '<<L<<' '<<R<<' '<<check(mid)<<endl;
//		mid=(L+R)/2;
//		
//		(check(mid)>check(L)){
//			L=mid+1;
////			cout<<L<<' '<<check(L)<<endl;
//		}
//		else{
//			R=mid-1;
//		}
//	}
////	return L;
//	return check(mid);
//}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
scanf("%lld%lld",&n,&m);
for(int i=1;i<=n;i++){
	scanf("%lld",&a[i]);
}
if(a[3]-a[2]==a[2]-a[1]){
	long long u=a[3]-a[2],sum=0,ans=0;
	for(int i=1;i<=n;i++){
		 sum+=u;
		 if((ans+sum)<=m)ans+=sum;
		 else{
		 	cout<<i-1;
		 	return 0;
		 }
	}
}
sort(a+1,a+n+1);
long long maxx=-1;
for(int i=1;i<=n;i++){
	maxx=max(maxx,check(i));
}
//for(int i=1;i<=n;i++)b[i]=b[i-1]+a[n]-a[i];
//for(int i=1;i<=n;i++){
//	
//}

//long long num=0;
//for(int i=1;i<=n;i++){
//b[i]=a[i]-a[i-1];
//
//if(b[i]<0){
//	long long o=b[i];
//	b[i]-=o;
//	b[i]-=o;
//}
//num+=b[i];
//cout<<a[i]<<" "<<b[i]<<endl;
//}
//cout<<num;
//long long p=1,sum=0;
//for(int i=1;i<=n;i++){
//cout<<sum<<' ';
//	if(sum+b[i]<=m)sum+=b[i];
//	
//	else{
//		cout<<i-1;
//		return 0;
//	}
//}
printf("%lld",maxx);
//for(int i=3835;i<=3845;i++)cout<<a[i]<<' '; 
	return 0;
} 
