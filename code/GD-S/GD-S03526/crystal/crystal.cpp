#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],pr[500005];
int n,m;
int ck(int l,int r){
	return pr[r]-pr[l]-(l-1)*(a[r]-a[l]);
}
int qey(int be,int ed){
	int l=be,r=ed;
//	cout<<ed<<" ";
	while(l<=r){
		int mid=(l+r)>>1;
		int us=ck(mid,ed);
		if(us<=m){
			r=mid-1;
		}else{
			l=mid+1;
		}
//		cout<<l<<" "<<r<<" ";
	}
//	cout<<'\n';
	return ed-l+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	pr[1]=0;
	for(int i=2;i<=n;i++){
		pr[i]=pr[i-1]+(i-1)*(a[i]-a[i-1]);
	}
//	for(int i=1;i<=n;i++)cout<<pr[i]<<" ";
//	cout<<'\n';
	int mx=0;
//	cout<<ck(1,3)<<'\n';
	for(int i=1;i<=n;i++){
		mx=max(mx,qey(1,i)); 
	}
	cout<<mx<<'\n';
	return 0;
}/*
5 5
1 2 4 8 9 

5 8
-3 -1 2 2 7
*/ 
