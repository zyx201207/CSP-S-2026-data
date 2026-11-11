#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long i,j,k;
long long dp[10005][2005];
long long a[200005];
bool B=0,A=0;
bool istrue(long long x){
	for(i=1;i<=30;i++){
		if(x==pow(2,i)-1)return true;
	}
	return false;
}
long long maxn(long long x){
	long long y;
	while(x>0){
		if(x%2==0)y++;
		x/=2;
	}
	return y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1){
			B=1;
		}
		if(istrue(a[i])==false){
			A=1;
		} 
	}	
	if(m==n-1){
		sort(a+1,a+n+1);
		long long sum=0,f;
		a[0]=-1;
		for(i=1;i<=n;i++){
			if(sum<maxn(a[i])){
				swap(a[0],a[i]);
			}
			if(a[i]==0){
				a[i]=-1;
				break;
			}
		}
		if(a[1]!=-1){
			sum=a[1];
			for(i=2;i<=n;i++){
				if(a[i]==-1)continue;
				sum&=a[i];
			}
		}
		else{
			sum=a[2];
			for(i=3;i<=n;i++){
				sum&=a[i];
			}
		}
		cout<<sum;
	}
	else if(A==0){
		sort(a+1,a+n+1);
		cout<<a[n-m];
	}
	else if(B==0){
		long long sum;
		if(n%2==1){
			sum=a[n];
			m--;
			for(i=n-2;i>0;i-=2){
				if(m==0)break;
				sum&=a[i];
				m--;
			}
		}
		else{
			sum=a[n-1];
			m--;
			for(i=n-3;i>0;i-=2){
				if(m==0)break;
				sum&=a[i];
				m--;
			}
		}
		cout<<sum;
	}
	else{
		for(i=1;i<=n;i++){
			dp[i][1]=a[i];
		}
		for(i=1;i<=m;i++){
			dp[1][i]=a[1];
		}
		for(i=1;i<=n;i++){
			for(j=m;j>0;j--){
				for(k=1;k<i;k++){
					dp[i][j]=max({dp[i][j],dp[i-k][j-1]&a[i],dp[i-1][j]});
				}
			}
		}
		cout<<dp[n][m];
	}
	return 0;
}

