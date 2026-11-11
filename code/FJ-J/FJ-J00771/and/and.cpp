#include<bits/stdc++.h>
using namespace std;
int num[100000];
int n,m;
int c[100000];
int d[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	if(m==1){
		int ans=-10000000;
		for(int i=1;i<=n;i++){
			ans=max(ans,num[i]);
		}
		cout<<ans;
		return 0;
	}else if(n<=20){
		int ans=-100000;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=0,a=num[i],b=num[j],sum=0;
				while(a!=0){
					cnt++;
					c[cnt]=a%2;
					a/=2;
				}
				cnt=0;
				while(b!=0){
					cnt++;
					d[cnt]+=b%2;
					b/=2;
				}
				for(int i=1;i<=cnt+1;i++){
					if(c[i]==1&&d[i]==1){
						sum+=pow(2,i-1);
					}
				}				
				ans=max(ans,sum);
			}
				
			
		}
		cout<<ans;
	}
	return 0;
}
