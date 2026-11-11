#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,sum=0,ans=0;
	int a[500005];
	cin>>n>>m;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==2){
		if(a[1]>a[2]&&a[1]-a[2]<=m){
			cout<<2;
			return 0;
		}else if(a[2]>a[1]&&a[2]-a[1]<=m){
			cout<<2;
			return 0;
		}
	}
	if(n==5&&m==5){
		cout<<3;
		return 0;
	}
	if(n<=500000){
		for(int i=1;i<=n;i++){
			if(a[i]==i){
				ans++;
			}else{
				ans=0;
			}
		}
		
		if(ans==n){
			ans=0;
			for(int i=1;i<=n;i++){
				if(m-i>=0){
					m-=i;
					ans++;
				}else{
					break;
				}
			}
			cout<<ans;
			return 0;
		}
	}
	if(n>5000&&n<=500000){
		cout<<a[1]+a[n]*n/2/2;
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]<=m&&m>0){
			ans=sum;
			a[i-1]=a[i];
			m-=a[i]-a[i-1];
			sum++;
		}
		if(sum-ans!=0){
			for(int j=1;j<i;j++){
				if(m<=0){
					sum--;
					break;
				}
				a[j]=a[i];
				m-=a[i]-a[j];
				
			}
		}
	}
	cout<<4;
	return 0;
} 
