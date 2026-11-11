#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m,a[N],s[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(ll x=1,y=1;x<=n;x++){
		while(y<=n){
			ll sum=s[y]-s[x-1];
			ll per=sum/(y-x+1);
			ll l=x-1,r=y+1,p=0;
			while(l+1<r){
				int mid=(l+r)/2;
				if(a[mid]<=per){
					p=l=mid;
				}else{
					r=mid;
				}
			}
			ll val=(2*p-x-y+1)*per+s[x-1]+s[y]-2*s[p];
			if(val>m) break;
			y++;
		}
		ans=max(ans,y-x);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
