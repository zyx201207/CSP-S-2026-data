#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	long long num=1,sum=0,sum1=0,sum2=n-1,sum3=0;
	ans++;
	if(n<=5000){
		for(int i=n;i>=1;i--){
			num=1,sum=0,sum1=0,sum2=n-1,sum3=0;
			for(int j=i-1;j>=1;j--){
				sum1+=b[j];
				if(sum+sum1<=m){
					sum+=sum1;
					num++;
				}
				else{
					break;
				}
			}
			if(num>ans){
				ans=num;
			}
		}
	}
	else{
		num=1,sum=0,sum1=0,sum2=n-1,sum3=0;
		for(int i=n-1;i>=1;i--){
			sum1+=b[i];
			if(sum+sum1<=m){
				sum3++;
				num++;
				sum+=sum1;
			}
			else{
				sum-=(sum3*b[sum2]);
				sum1-=b[sum2];
				
				if(num>ans){
					ans=num;
				}
				sum2--;
				if(sum3>0){
					sum3--;
				}
				
				if(num>1){
					num--;
				}
				if(sum+sum1<=m){
					sum3++;
					num++;
					sum+=sum1;
				}
			}
			
		}
	}
	if(ans<num){
		ans=num;
	}
	cout<<ans;
	return 0;
} 
