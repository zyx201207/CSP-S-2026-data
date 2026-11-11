#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[100009],c[100009],ans,zs,bc,xb;
bool yz=false;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    
    for(ll i=1;i<=n;i++){
    	cin>>a[i];
    	if(i>1&&a[i]!=a[i-1]){
    		yz=true;
		}
	}
	if(m==0){
    	cout<<0;
    	return 0;
	}
	if(yz==false){
		if(m<=n){
			cout<<m;
			return 0;
		}
		else{
			cout<<n;
			return 0;
		}
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
    	c[i]=c[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			zs=c[j]-c[i-1];
			if((zs+m)%(j+1-i)==0&&(zs+m)/(j+1-i)>=a[j]){
			if((j+1-i)>ans){
				ans=max(ans,j+1-i);
				bc=zs+m;
				xb=j;
			}
			
		    }
		}
    	
	}
	for(ll i=xb+1;i<=n;i++){
		if(a[i]==bc/ans){
			ans++;
		}
		
	}
	
	cout<<ans;
	
//	5 8
//   -3 -1 2 2 7
	return 0;
}
