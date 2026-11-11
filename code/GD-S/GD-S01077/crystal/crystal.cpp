#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define ROF(i,a,b) for(int i=(int)b;i>=(int)a;i--)
#define ll long long 
#define ull unsigned long long
const int N=1e6+10;
const ll mod=1e9+7;
const ll inf=1e18+10;
using Vl=vector<int>;
using PI=array<int,2>;
int n,ans=0;ll m,a[N],pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m;
	FOR(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	FOR(i,1,n){
		pre[i]=pre[i-1]+a[i];
		int L=1,R=i,mid,res=0;
		while(L<=R){
			mid=L+R>>1;
			if(a[i]*mid-(pre[i]-pre[i-mid])<=m) res=mid,L=mid+1;
			else R=mid-1;
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
/*
5 5
2 1 2 4 8 9

5 8
-3 -1 2 2 7
*/
