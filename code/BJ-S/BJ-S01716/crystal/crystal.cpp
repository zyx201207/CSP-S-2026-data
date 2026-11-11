#include<bits/stdc++.h>
using namespace std;
int n,m,a[500234],dn,mx=-1;
int fk(int c,int n){
	int l=1,mid=n-1;
	while(mid>0){
		mid/=2;
		if((n-mid)*(a[n]-a[n-1])-a[n]+a[mid+1]>m) l+=mid;
		else l-=mid;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
    for(int i=1;i<n;i++){
       mx=max(mx,a[i+1]-a[i]);
    }
	if(mx>m){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	a[0]=0;
	for(int i=2;i<=n;i++){
		int d=fk(a[i]-a[i-1],i);
		dn=max(dn,i-d);
	}
	cout<<dn;
	return 0;
}/*5 8
-3 -1 2 2 7*/
