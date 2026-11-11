#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200007],z[200007],c[200007],usd[99999999],ans;
long long p[35]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
long long jz(long long x){
	long long i,cnt=2,t=1,sum=0;
	for(i=2;i<=30;i++){
		if(cnt>=x) break;
		cnt*=2;
	}
	for(int j=i-1;j>=1;j--){
		if(x>=cnt){
			x-=cnt;
			sum+=1;
			sum*=10;
			cnt/=2;
		}
		else{
			sum*=10;
			cnt/=2;
		}
	}
	if(x%2==1) sum+=1; 
	return sum;
}
long long wy(long long a,long long b){
	int sum=0,cnt[35],m=1;
	while(a>0&&b>0){
		int x=a%10,y=b%10;
		if(x==y&&x>0&&y>0){
			cnt[m]=1;
			m++;
		}
		else{
			cnt[m]=0;m++;
		}
		a/=10;b/=10;
	}
	for(int i=1;i<m;i++){
		if(cnt[m-i]==1){
			sum+=1;sum*=10;
		}
		else sum*=10;
	}
	return sum/10;
}
long long sjz(long long x){
	long long sum=0,cnt=0;
	while(x>0){
		if(x%10==1){
			sum+=p[cnt];
			cnt++;
		}
		else cnt++;
		x/=10;
	}
	return sum;
}
void DFS(long long st,long long sum,long long i){
	if(st>=m+1){
		ans=max(ans,sjz(sum));
		return ;
	}
	for(int j=i+1;j<=n;j++){
		DFS(st+1,wy(sum,z[j]),j);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		z[i]=jz(a[i]);
	}
	for(int i=1;i<=n;i++){
		usd[sjz(z[i])]=1;
		DFS(1,z[i],i);
	}
	cout<<ans;
	return 0;
}
