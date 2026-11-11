#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[510000],d=1e18,tot=1,cha[510000],ans=1;
struct node{
	int l,r;
};
vector<node>td[510000];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(i>1&&a[i]-a[i-1]==d)tot++;
		if(i>1) d=a[i]-a[i-1];
		if(i>1)cha[i]=a[i]-a[i-1];
	}
	if(tot==n-1){
		if(d==0)cout<<n;
		else{
			int k=(n%2==1?n/2+1:n/2),i=1;
			while(m-i*2*d>=0&&i<k){
				m-=i*2*d;
				ans+=2;
				i++;
			}
			if(i==k&&k*2==n+1)cout<<ans;
			else if(i==k&&k*2==n){
				if(m>=k*d)cout<<ans+1;
				else cout<<ans;
			}
			else if(m>=i*d)cout<<ans+1;
			else cout<<ans;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(ans>=n-i+1)break;
		for(int j=i+1;j<=n;j++){
			if(ans>=j-i+1)continue;
			int k=(j+i)>>1,km=0,l=i;
			while(km<=m&&l<=j){
				if(km+abs(a[l]-a[k])<=m)km+=abs(a[l]-a[k]);
				else break;
				l++;
			}
			if(l==j+1)ans=max(ans,j-i+1);
			else break;
		}
	}
	cout<<ans;
	return 0;
} 
/*
-3 -1 2 2 7
2 3 0 5
*/
