#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=2e5+10;
int n,m,ans;
struct Node{
	int num,tnum;
}a[N];
bool cmp(Node a,Node b){
	return a.num>b.num;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].num;
	sort(a+1,a+n+1,cmp);
	ans=a[m].num;
	cout<<ans;
	return 0;
}
