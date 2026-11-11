#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],dcli=1,x,ans,y;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		if(a[2]-a[1]!=a[i]-a[i-1]) dcli=0;
	}
	if(dcli){
		x=a[2]-a[1];
		while(m>=0){
			y++;
			m-=y*x;
			if(y>n){
				break;
			}
		}
		cout<<min(y,n);
	}
	else{
		for(int i=1;i<=n;i++){
			long long sum=1;
			long long lm=m;
			for(int j=i-1;j>=1;j--){
				if(lm-a[i]+a[j]>0){
					lm-=a[i]-a[j];
					sum++;
				}
				else if(lm-a[i]+a[j]<0){
					ans=max(ans,sum);
					break;
				}
				else{
					ans=max(ans,sum+1);
					break;
				}
				if(j==1){
					ans=max(ans,sum);
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
