#include <bits/stdc++.h>
using namespace std;
	long long n,m,a[100000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(ans<a[i]){
				ans=a[i];
			}
		}
		cout<<ans;
	}else if(m==2){
		long long sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long x=a[i]&a[j];
				sum=max(sum,x);
			}
		}
		cout<<sum;
	}else if(m==n){
		long long num=a[1];
		for(int i=2;i<=n;i++){
			num=num&a[i];
		}
		cout<<num;
	}else{
		long long x=a[1],sum=0,c=0;
		for(int i=1;i<=n;i++){
			c=1;
			if(i==1){
				c=2;
				x=a[2];
			}else{
				x=a[1];
			}
			for(int j=2;j<=n;j++){
				if(j!=i&&j!=c){
					x=x&a[j];
				}
			}
			sum=max(sum,x);
		}
		cout<<sum;
	}
	return 0;
}
