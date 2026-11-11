#include<bits/stdc++.h>
using namespace std;
#define LL long long
struct st{
	LL sl;
	char ch;
}a[400000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++) cin>>a[i].sl>>a[i].ch;
	LL l=1,r=n,ans=0;
	while(l<r){
		LL x=min(a[l].sl,a[r].sl);
		if(a[l].ch!=a[r].ch) ans+=x;
		a[l].sl-=x;
		a[r].sl-=x;
		if(a[l].sl==0) l++;
		if(a[r].sl==0) r--;
	}
	cout<<ans;
	return 0;
}
