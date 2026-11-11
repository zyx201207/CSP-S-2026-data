#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],b[N];
ll get(int l,int r){
	if(l==r) return 0;
	return a[r]*(r-l+1)-b[r]+b[l-1];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0);
	int n; ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int l=1,r=1;
	for(;r<=n;r++){
		while(l<=r && get(l,r)>m) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
