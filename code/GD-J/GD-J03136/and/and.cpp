#include<bits/stdc++.h>
using namespace std;

vector<int> d,tmp;
int n,m,ans;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int a,i=1;i<=n;i++) 
		cin>>a,d.push_back(a);
	for(int i=30;i>=0;i--)
	{
		tmp.clear();
		for(int a:d) if(a&(1<<i)) tmp.push_back(a);
		if(tmp.size()>=m) d.swap(tmp),ans|=(1<<i);
//		cout<<i<<' '<<ans<<'\n';
//		for(int a:tmp) cout<<a<<' ';
//		cout<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
}
