#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,sum=0,a[200007],max=-1e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			sum=a[i];
			if(sum>max) max=sum;
		}
		cout<<max;
		return 0;
	}if(m==n){
		sum=a[1];
		for(int i=1;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				sum=a[i]&a[j];
				if(sum>max) max==sum;
			}
		}
		cout<<sum;
		return 0;
	}
	else {
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]==a[j]) sum=a[i];
				if(sum>max) max=sum;
			}
		}
		cout<<max;
		return 0;
	}
	return 0;
}
