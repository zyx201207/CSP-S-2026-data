#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,ans,l=1,r,minn;
struct node{
	ll o;
	char c;
}a[20005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i].o>>a[i].c,r+=a[i].o;
	while(l<=r){
		if(a[l].c==a[r].c)minn=min(a[l].o,a[r].o),ans+=minn,l+=minn,r-=minn;
		else minn=min(a[l].o,a[r].o),l+=minn,r-=minn;
	}
	cout<<ans<<"\n";
	return 0;
}
