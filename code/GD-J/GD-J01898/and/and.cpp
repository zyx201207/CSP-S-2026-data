#include <bits/stdc++.h>
using namespace std;
long long n,i,j,k,y,m,len,s,l,r,ans,cnt;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=(1<<30);i>=1;i>>=1){
		cnt=0;
		for(j=1;j<=n;j++){
			if(a[j]>=i){
				cnt++;
			}
		}
		if(cnt>=m){
			ans+=i;
			for(j=1;j<=n;j++){
				if(a[j]<i){
					a[j]=0;
				}
				else{
					a[j]-=i;
				}
			}
		}
		else{
			for(j=1;j<=n;j++){
				if(a[j]>=i){
					a[j]-=i;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
