#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxi,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		maxi=max(a[i],maxi);
	} 
	if(m==1){
		cout<<maxi;
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans=(ans&a[i]);
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));		
			}
		}
		cout<<ans;
	}
	return 0;
} 

