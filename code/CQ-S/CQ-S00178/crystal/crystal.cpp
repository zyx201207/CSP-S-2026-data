#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N=5e5+6;
int n,m,a[N],l=1,r=1;
int q[N],yly,k,id;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) q[i]=q[i-1]+a[i];
	while(r<=n){
		id=1;
		while(k<=m&&r<n) id=0,yly=max(yly,r-l+1),r++,k=a[r]*(r-l+1)-(q[r]-q[l-1]);
		while(k>m&&l<r) id=0,l++,k=a[r]*(r-l+1)-(q[r]-q[l-1]);
		if(id) break;
	}
	cout<<yly;
	return 0;
}
