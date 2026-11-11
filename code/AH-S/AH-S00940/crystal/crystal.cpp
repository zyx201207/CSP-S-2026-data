#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll a[N],s[N],n,m,ans;
bool check(int k,int i){
	return a[i]*k-(s[i]-s[i-k])<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ll l=0,r=i+1,mid;
		while(l+1<r){
			mid=l+r>>1;
			if(check(mid,i))l=mid;
			else r=mid;
		}
		//if(!check(1,i))cout<<"!\n";
		//cout<<l<<' ';
		ans=max(ans,l);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
