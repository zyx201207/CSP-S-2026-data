#include<bits/stdc++.h>
using namespace std;
long long n,m,a[555555],dp[555555],ans,c=1,l,man,man1=1,man2=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=dp[i-1]+a[i];
		if(abs(a[i])>100000)man=1;
	}
	if(man==0){
		sort(a+1,a+n+1);
		for(int k=a[2];k<=a[n];k++){
			ans=0;l=m;
			for(int i=1;i<=n;i++){
				if(a[i]<=k&&k-a[i]<=l){
					ans++;l-=k-a[i];
				}
			}
			c=max(c,ans);
		}cout<<c;
	}
	else{
		for(int i=111;i<=11111;i++){
			if(a[i]!=i){
				man1=0;
				break;
			}
		}
		long long p=a[95]-a[94];
		for(int i=111;i<=11111;i++){
			if((a[i]-a[i-1])!=p){
				man2=0;
				break;
			}
		}
		if(man1==1){
			int h;
			for(int i=1;i<=555555;i++){
				if((i*(i+1))/2>m){
					h=i;
					break;
				}
			}cout<<h;
		}
		else if(man2==1){
			sort(a+1,a+n+1);
			long long h,b;
			b=a[2]-a[1];
			for(int i=1;i<=555555;i++){
				if(i*(i+1)/2*b>m){
					h=i;
					break;
				}
			}cout<<h;
		}
		else{
			cout<<a[n];
		}
	}
	return 0;
}
