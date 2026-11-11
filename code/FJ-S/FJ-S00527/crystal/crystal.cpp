#include<bits/stdc++.h>
using namespace std;
long long n,m,a[700000],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		long long c=0,x=0;
		for(int j=i;j>=1;j--){
			c+=a[i]-a[j];
			x++;
			if(c<=m){
			ans=max(ans,x);
		    }else{
		    	break;
			}
		}
	}
	cout<<ans;
	return 0;
}
