#include<bits/stdc++.h>
using namespace std;
long long n,k=1,ans=1;
long long m,q[5005][5005],a[500005];


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long x=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=x) k=0;
	}
	if(k==1){
		int t=0;
		for(int i=2;i<=n;i++){ 
			long long y=i;
			if(y%2==0){
				if(x*y*(y-1)/2+y/2>m){
					ans=y-1;
					t=1;
					break;
				}
			}else{
				if(x*y*(y-1)/2>m){
					ans=y-1;
					t=1;
					break;	
				}
			}
		}
		if(t==0) ans=n;
	}else if(n<=5000){
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++) q[i][j]=q[i-1][j]+(a[i]-a[i-1])*(i-j);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(q[i][j]<=m&&i-j+1>ans){
					ans=i-j+1;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
