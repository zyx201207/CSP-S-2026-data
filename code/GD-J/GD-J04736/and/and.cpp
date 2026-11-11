#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],sum;
bool isA=1;
long long q(long long x){
	long long sum=0;
	for(int i=1;i<=n;i++){
		int s=a[i]&q(x+1);
		if(sum<s){
			sum=s;
		}
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n==m){
   		cin>>a[1];
   		sum=a[1];
    	for(int i=2;i<=n;i++){
    		cin>>a[i];
    		sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==1){
    	for(int i=1;i<=n;i++){
    		cin>>a[i];
    		if(a[i]>sum){
    			sum=a[i];
			}
		}
		cout<<sum;
		return 0;
	}
	if(n>2000 && m==n-1){
		long long s;
		cin>>a[1];
   		s=a[1];
    	for(int i=2;i<=n;i++){
    		cin>>a[i];
    		s=s&a[i];
		}
		for(int i=1;i<=n;i++){
			int w=!s^a[i];
			if(w>sum){
				sum=w;
			}
		}
		cout<<sum;
		return 0;
	}
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]&(a[i]+1)!=0 && isA) isA=false;
	}
	if(isA){
		sort(a+1,a+1+n);
		sum=a[n];
		for(int i=n;i>n-m;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int s=a[i]&a[j];
				if(s>sum){
					sum=s;
				}
			}
		}
		cout<<sum;
		return 0;
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					int s=a[i]&a[j]&a[k];
					if(s>sum){
						sum=s;
					}
				}
			}
		}
		cout<<sum;
		return 0;
	}
	if(n<=20 && m<=n){
		cout<<q(1);
		return 0;
	}
	cout<<0;
	return 0;
}
