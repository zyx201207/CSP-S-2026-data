#include<bits/stdc++.h>
using namespace std;
long long n,m,k,l=0;
int a[101000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
//		cout<<a[i]<<' '<<i<<endl;
	}
		long long sum;
	if(n<=5001){
		
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			k=m;
			sum=0;
			for(int j=i-1;j>=1;j--){
				if(k>=a[i]-a[j]){
					k-=(a[i]-a[j]);
//					cout<<i<<' '<<j<<' '<<k<<' '<<a[i]<<' '<<a[j]<<endl;
					
					sum++;
				}
			}
			l=max(l,sum);
			
		}
		cout<<l+1;
		return 0;
	}
	else{
		k=m;
		sum=0;
		for(int j=n;j>=1;j--){
			if(k>=a[n]-a[j]){
				k-=(a[n]-a[j]);
				sum++; 
			}
		}cout<<sum;
		return 0;
	}
} 





