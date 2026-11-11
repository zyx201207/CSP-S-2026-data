#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,l=1,ans;
#define ll long long
ll a[N],m,cur;
/*
5 5
1 2 4 8 9
*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int r=1;r<=n;r++){
		cur+=(a[r]-a[r-1])*(r-l);
		while(cur>m){
			cur-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
