#include <bits/stdc++.h>
using namespace std;
long long a[200100];
int n,m;
long long sum=0,ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==n){
		sum=a[n];
		for(int j=n-1;j>=1;j--) sum&=a[j];
		cout<<sum;
	}else if(m==1){
		cout<<a[n];
	}else if(m==2){
		for(int i=1;i<=n;i++){
			sum=max(a[i]&a[i+1],sum);
			for(int j=1;j<=n;j++){
				if(j!=i) sum=max(sum,a[i]&a[j]);
			}
		}
		cout<<sum;
	}else{
		int z=n-1;
		sum=a[n];
		for(int i=2;i<=m;i++){
			sum&=a[z];
			z--;
		}
	 	cout<<sum;
	}
	return 0;
}
