#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500010],ans;
ll c;
bool flag=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2){
			if(c!=a[i]-a[i-1])
			{
				flag=1;
			}
		}else if(i==2){
			c=a[i]-a[i-1];
		}
	}
	if(flag==0){
		ll sm=0,list=a[1];
		for(int j=1;j<=n;j++){
			sm+=(j-1)*(a[j]-list);
			cout<<sm<<" "<<(a[j]-list)<<"|";
			list=a[j];
			
			//cout<<ans<<" ";
			if(sm<=m){
				ans=max(1ll*j,ans);
			}else{
				break;
			}
		}cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ll sm=0,list=a[i];
		for(int j=i;j<=n;j++){
			sm+=(j-i)*(a[j]-list);
			//cout<<sm<<" ";
			list=a[j];
			if(sm<=m){
				ans=max(1ll*(j-i+1),ans);
			}else{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
