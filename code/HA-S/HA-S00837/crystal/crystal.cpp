#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define ft first
#define sd second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rem(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;

const LL N=5e5+10;
LL n,m;
LL a[N],pre[N];

int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	//freopen("crystal2.in","r",stdin);//freopen("std.out","w",stdout);//fc /W std.out 
	std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	rep(i,1,n) pre[i]=pre[i-1]+a[i];
	LL l=1,ans=0;
	rep(i,1,n){
		LL res=m-(a[i]*(i-l+1)-(pre[i]-pre[l-1]));
		while(res<0) res+=a[i]-a[l],l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}
