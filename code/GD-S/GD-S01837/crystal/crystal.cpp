#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],s[N];
int ans=1;
bool check(int x){
	int c=0,j=0;
	for(int i=x;i<=n;i++){
		j=i-x+1;
		c=(i-j)*a[i]-(s[i-1]-s[j-1]);
		if(c<=m)return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	s[0]=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n;
	int mid=0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=max(ans,mid);
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
} 
/*
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9

*/
