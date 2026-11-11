#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 
#define fi first
#define se second
typedef long long ll;
const int N=2e5+5;
int n,m,cnt;
pii a[N];
bool flag;
int f(int v){
	int ans=0;
	while(v>0){
		if(v&1)ans++;
		v>>=1;
	}
	return ans;
}
bool cmp(pii a,pii b){
	if(a.se!=b.se)return a.se>b.se;
	return a.fi>b.fi;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].fi;
		if(a[i].fi!=i-1)flag=1;
		a[i].se=f(a[i].fi);
	}
	if(!flag){
		cout<<n-m;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		if(i==1)cnt=a[i].fi;
		else cnt&=a[i].fi;
	}
	cout<<cnt;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

*/

