#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e8+5;
ll n,a[N],mid,ans;
char c[N],qw;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    
    cin>>n;
    for(ll i=1;i<=n;++i){
    	cin>>a[i]>>c[i];
    	ans+=a[i];
    	if(i==1) qw=c[i];
    	if(qw!=c[i]) mid=1;
    }
    if(mid==0 || n==1){
    	cout<<0;
    	return 0;
    }else if(n==2){
    	if(a[1]>a[2]) cout<<a[1]-a[2];
    	else cout<<a[2]-a[1];
    	return 0;
    }else{
    	cout<<ans/2;
    	return 0;
    }
    
	return 0;
}
