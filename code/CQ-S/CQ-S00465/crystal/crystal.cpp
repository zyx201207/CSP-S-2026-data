#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll>
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;
bool bbb;
const int N=5e5+5;
ll n,m,a[N],ans,s[N];
void fast(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return;
}
bool eee;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	fast();
	//cerr<<abs(&bbb-&eee)/1024.0/1024.0<<endl; 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ll l=1,r=i,mid,res=-1;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[i]*mid-s[i]+s[i-mid]<=m) l=mid+1,res=mid;
			else r=mid-1;
		}	
		ans=max(ans,res);
	}
	cout<<ans<<endl; 
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
