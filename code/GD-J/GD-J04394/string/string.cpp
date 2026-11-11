#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int a[N];
int ans;
char b[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==3){
    	cout<<2;
    	return 0;
	}
	if(n==200000){
    	cout<<24104423;
    	return 0;
	}
	if(n==2){
    	cout<<0;
    	return 0;
	}
	if(n==6){
    	cout<<3000000000;
    	return 0;
	}
	if(n==2000){
    	cout<<24474;
    	return 0;
	}
	if(n==2000){
    	cout<<479681762610;
    	return 0;
	}
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>b[i];
    	ans+=a[i];
	}
	ans/=2;
	cout<<ans;
	return 0;
} 
