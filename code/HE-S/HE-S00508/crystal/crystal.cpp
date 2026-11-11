#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,num;
ll a[500005],s[500005];
int main(){ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i];
	}
		for(ll i=n-1;i>=1;i--){
			while(m>0){
			if(a[i]=i){
				a[i]=a[i+1];
				num++;
				if(m-(a[i]-s[i])>=0){
					m-=a[i]-s[i];
				}
			}
	    }  
 } cout<<num;
	return 0;
}
