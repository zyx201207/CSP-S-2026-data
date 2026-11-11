#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int x,y;
}a[200005];
int sy(int t)
{
	int cnt=0;
	while(t!=0)
	{
		cnt+=t%2;
		t/=2;
	}
	return cnt;
}
bool cmp(node p,node q)
{
	if(p.y==q.y)
	return p.x>q.x;
	return p.y>q.y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].y=sy(a[i].x);
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m].x;
	return 0;
}
