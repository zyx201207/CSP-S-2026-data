#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define D long double
#define int long long 
#define N 1000006
int a[N],qz[N];int n,m;
inline bool getans(int l,int r){
	int mx=a[r],sum=qz[r]-qz[l-1];
	//cerr<<"NOW: "<<l<<" "<<r<<" : "<<((r-l+1)*mx-sum)<<endl;
	if(((r-l+1)*mx-sum)<=m)	return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)	qz[i]=qz[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=i,r=n,tans=i;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(getans(i,mid))	l=tans=mid;
			else	r=mid-1;
		}
		ans=max(ans,tans-i+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
