#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,ans;
struct tni{
	LL cnt,val;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++){
		char ch;
		cin>>a[i].cnt>>ch;
		a[i].val=(LL)(ch-'a'+1);
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	LL l=1,r=n;
	while(l<r){
		LL tmp=min(a[l].cnt,a[r].cnt);
		if(a[l].val!=a[r].val) ans+=tmp;
		a[l].cnt-=tmp;
		a[r].cnt-=tmp;
		if(a[l].cnt==0) l++;
		if(a[r].cnt==0) r--;
	}
	cout<<ans;
	return 0;
}
