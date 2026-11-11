#include<bits/stdc++.h>
using namespace std;
struct num{
	int sum;
	char sub;
}a[27891];
int main(){
	long long n,len=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].sub; 
		len+=a[i].sum;
	} 
	for(int i=1;i<=n/2;i++){
		for(int j=n;j>=n/2;j--){
			if(a[i].sub==a[j].sub) continue;
			ans+=a[j].sum;
			if(a[j].sum<a[i].sum){
				a[i].sum-=a[j].sum;
				for(int k=j-1;k>=n;k--){
					if(a[k].sub==a[i].sub){
						if(a[k].sum>=a[i].sum){
							break;
						}
					}else{
						if(a[k].sum>=a[i].sum){
							ans+=a[i].sum;
						}else{
							ans+=a[k].sum;
						}
					}
				}
			}
			if(a[j].sum>a[i].sum){
				ans=ans-a[j].sum+a[i].sum;
			}
			a[j].sum=0;
		}
	}
	cout<<ans;
	return 0;
}
