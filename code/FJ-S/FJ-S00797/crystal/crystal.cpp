#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	if(m/(n-1)>a[n]-a[1]) cout<<n;
	else{
		if(n<=5000){
			long long u=1,sum=m,maxx=1;
			for(int j=2;j<=n;j++){
				sum=m;
				u=1;
				for(int k=j-1;k>=1;k--){
					if((a[j]-a[k])<=sum){
						sum-=(a[j]-a[k]);
						u++;
					}else break;
				}maxx=max(maxx,u);
			}cout<<maxx;
		}else{
			long long gg=a[2]-a[1];
			if(gg==0) cout<<n;
			else{
				long long l=0;
				while(m>0){
					if(gg*(l+1)<=m){
						l++;
						m-=gg*l;
					}else{
						break;
					}
				}cout<<l+1;
			}
		}
	}
	return 0;
}
