#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m;
int maxx;
int ans;
struct edge{
	int x,cnt;
}a[N];

bool cmp(edge u,edge v){
	if(u.cnt!=v.cnt) return u.cnt>v.cnt;
	else return u.x>v.x;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		maxx=max(maxx,a[i].x);
		a[i].cnt=__builtin_popcount(a[i].x);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
//	for(int i=1;i<=n;i++) cout<<a[i].x<<' ';
	ans=a[1].x;
	int cnt=0;
	for(int i=2;i<=m+cnt;i++){
		if((ans&a[i].x)!=0) ans=ans&a[i].x;
		else cnt++;
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
