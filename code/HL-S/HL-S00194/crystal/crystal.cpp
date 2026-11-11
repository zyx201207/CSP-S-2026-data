#include<bits/stdc++.h>
#define ll long long
#define i128 __int128
using namespace std;
const int maxn =5e5+10;
int n;
ll m,a[maxn],ans=1,p=1;
ll tmp,res,seg[maxn];
ll mx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)seg[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++){
		ans++;
		res+=seg[i]*1ll*ans;
	       tmp+=seg[i];
		while(res>m){
			ans--;res-=tmp;tmp-=seg[p];p++;
		}
		mx=max(mx,ans); 
	}
	cout<<mx+1;
	return 0;
}
