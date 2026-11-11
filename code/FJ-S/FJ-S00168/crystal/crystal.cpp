#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans=1,b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			b[i]=b[i-1]+a[i]-a[i-1];
		}
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(m>=b[i]){
			ans=max(ans,i);
		}else{
			for(int j=2;j<=i-1;j++){
				if(m>=b[i]-b[j]){
					ans=max(ans,i-j+1);
					break;
				}
			}	
		}
	}
	cout<<ans;
	return 0;
}
