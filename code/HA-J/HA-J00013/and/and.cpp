#include<bits/stdc++.h>
using namespace std;
int n,m;
int bit[40];
int bit2[40];
long long a[200010];
long long ans;
bool A,B;
bool pd(long long x){
	int cntt=0;
	while(x){
		cntt+=(x&(long long)(1));
		x>>=1;
	}
//	cout<<cntt<<"*\n";
	return cntt==m;
}
void f(long long x){
	long long tans=(1<<30)-1;
	for(int i=n;i>=1;i--){
		if(x&(long long)(1)){
			tans&=a[i];
		}
		x>>=1;
	}
	ans=max(ans,tans);
}
bool pd2(long long x){
	if(x==0)return 1;
	while(x){
		if(!(x&1))return 0;
		x>>=1;
	}
	return 1;
}
void pd3(long long x){
	int cnti=-1;
	while(x){
		cnti++;
		if(x&1)bit2[cnti]++;
		x>>=1;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	A=1,B=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!pd2(a[i]))A=0;
		if(a[i]!=i-1)B=0;
	}
	B=B&pd2(n-1);
	if(m==1){
		long long maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);	
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		long long sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];	
		}
		cout<<sum;
		return 0;
	}
	if(m==n-1){//
		long long ansm=0;
		for(int i=1;i<=n;i++){
			pd3(a[i]);
		}
//		for(int i=0;i<=10;i++){
//			cout<<bit2[i]<<"*\n";
//		}
		for(int i=35;i>=0;i--){
			if(bit2[i]==n-1){
				ansm=(1<<30)-1;
				for(int j=1;j<=n;j++){
					if(a[j]&(1<<i))ansm&=a[j];
				}
				break;
			}
		}
		cout<<ansm;
		return 0;
	}
	if(m==2){
		long long ans2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans2=max(ans2,a[i]&a[j]);
			}
		}
		cout<<ans2;
		return 0;
	}
	if(A){
		for(int i=1;i<=n;i++){
			bit[(int)(log2(a[i]+1))]++;
		}
		int ttsum=0;
		for(int i=35;i>=0;i--){
			ttsum+=bit[i];
			if(ttsum>=m){
				cout<<((long long)(1)<<i)-1;
				return 0;
			}
		}
	}
	for(long long i=0;i<((long long)(1)<<n);i++){
		
		if(!pd(i))continue;
//		cout<<i<<"\n";
		f(i);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

*/
