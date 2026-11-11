#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define ll long long
const int N=2e5+10;
//l表示访问到第几个数,r同理
//lp表示访问到数字第几位,rp同理 
ll n,l,lp,r,rp,ans;
char c[N];
ll a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
    l=1ll,r=n;
    for(ll i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
	}
	while(l<r){
		if(a[l]-lp>a[r]-rp){
			if(c[l]!=c[r]){
				ans+=a[r]-rp;
			}
			lp+=a[r]-rp;
			rp=0ll,r--;
		}
		else if(a[l]-lp<a[r]-rp){
			if(c[l]!=c[r]){
				ans+=a[l]-lp;
			}
			rp+=a[l]-lp;
			lp=0ll,l++;
		}
		else{
			if(c[l]!=c[r]){
				ans+=a[r]-rp;
			}
			rp=0ll,r--;
			lp=0ll,l++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
