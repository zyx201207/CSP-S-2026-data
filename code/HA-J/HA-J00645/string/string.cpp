#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[500005],l=1,cnt=0,r;
char c[500005];
void cxl(ll q,ll w,int o){
	ll p=min(a[q],a[w]);
	a[q]-=p;
	a[w]-=p;
	if(o) cnt+=p;
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	r=n;
	while(l<r){
		if(c[l]==c[r]){			//CCFsm
			cxl(l,r,0);
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
		else{
			cxl(l,r,1);
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
	}
	cout<<cnt;
	return 0;
}
