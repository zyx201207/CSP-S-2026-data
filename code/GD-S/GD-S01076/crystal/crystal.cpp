#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned ll
using VI=vector<int>;
using PI=pair<int,int>;
const int N=5e5+5;
ll n,m,a[N],s[N],mx[N][23];
void init(){
	for(int j=1;j<=22;j++){
		for(int i=1;i+(1<<j)-1<=n;i++)
		mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
	}
}
ll query(int l,int r){
	int k=__lg(r-l+1);
	return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
bool check(int len){
	for(int i=len;i<=n;i++){
		int l=i-len+1;
		ll L=s[i]-s[l-1],R=L+m;
		ll res=R/len;
		if(query(l,i)>res)continue;
//		cout<<len<<" "<<i<<" "<<L<<" "<<R<<"\n";
//		if(len==4&&i==5)cout<<query(l,i)<<"\n";
		return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		mx[i][0]=a[i];
	}
	init();
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;return 0;
}
/*
5 5
1 2 4 8 9
*/
