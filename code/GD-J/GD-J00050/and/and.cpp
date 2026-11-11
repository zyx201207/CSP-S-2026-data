#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long n,m,maxn,ans,ans1;
struct node{
	long long a;
	string s;
}a[N];
bool cmp(node x,node y){
	return x.s>y.s;
}
bool cmp1(node x,node y){
	return x.a>y.a;
}
vector<long long>ap;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i].a;
	for(long long i=1;i<=n;i++){
		long long t=a[i].a,cnt=0;
		while(t){
			a[i].s=char(t%2+48)+a[i].s;
			t/=2;
			cnt++;
		}
		maxn=max(cnt,maxn);
	}
	sort(a+1,a+1+n,cmp1);
	for(long long i=1;i<=n;i++)while(a[i].s.size()<maxn)a[i].s="0"+a[i].s;
	sort(a+1,a+1+n,cmp);
	ans=a[1].a;
	for(long long i=2;i<=m;i++)ans=(ans&a[i].a);
	cout<<max(ans,ans1);
	return 0;
}
