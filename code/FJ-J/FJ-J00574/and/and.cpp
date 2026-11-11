#include<bits/stdc++.h>
using namespace std;
int n,m,b[35];
long long ans=(1<<30)-1;
bool ybit[35];
struct st
{
	long long a;
	bool b[35];
}a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i].a;
	for(int i=0;i<n;i++)
		for(int j=0;j<30;j++)
			if(a[i].a&(1<<j))
				a[i].b[j]=1,
				b[j]++;
	for(int i=0;i<30;i++)
		if(b[i]>=m)
			ybit[i]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<30;j++)
			if(!ybit[j])
				a[i].b[j]=0;
	sort(a,a+n,[](st q,st w){
		for(int i=29;i>=0;i--)
			if(q.b[i]!=w.b[i])
				return q.b[i]>w.b[i];
		return false;
	});
	for(int i=0;i<m;i++)
		ans&=a[i].a;
	cout<<ans;
	return 0;
}
