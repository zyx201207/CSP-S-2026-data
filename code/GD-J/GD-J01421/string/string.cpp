#include<bits/stdc++.h>
using namespace std;
struct t2
{
	long long n;
	char c;
};
long long n,ans;
list<t2>lst;
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int u;
		char cc;
		cin>>u>>cc;
		lst.push_back({u,cc});
	}
	while(lst.size()>1)
	{
		t2 l,r;
		int mi;
		l=lst.front();lst.pop_front();
		r=lst.back();lst.pop_back();
		mi=min(l.n,r.n);
		l.n-=mi,r.n-=mi;
		if(l.c!=r.c)ans+=mi;
		if(l.n)lst.push_front(l);
		if(r.n)lst.push_back(r);
	}
	cout<<ans;
	return 0;
}
