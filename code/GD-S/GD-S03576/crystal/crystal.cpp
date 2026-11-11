#include<bits/stdc++.h>
using namespace std;
struct ss{
	long long unsigned b;
	long long unsigned ym;
};
queue<ss> q;
long long unsigned n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long unsigned i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	q.push({1,m});
	for(long long unsigned i=2;i<=n;i++)
	{
		if(q.size()*(a[i]-a[q.back().b])<=q.back().ym)
			q.push({i,q.back().ym-q.size()*(a[i]-a[q.back().b])});
		else if((q.size()-1)*(a[i]-a[q.back().b])<=a[q.back().b]-a[q.front().b])
		{
			q.pop();
			q.push({i,q.back().ym-(q.size()-1)*(a[i]-a[q.back().b])+a[q.back().b]-a[q.front().b]});
		}
	}
	cout<<q.size();
	return 0;
}
