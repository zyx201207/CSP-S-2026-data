#include<bits/stdc++.h>
using namespace std;
int a[500005], ans[300005];
void func(int b,int e,int m)
{
	vector<int> t;
	for(int i=b;i<=e;i++)
	{
		t.push_back(a[i]);
		auto it=find(t.begin(),t.end(),a[i]);
		int id=it-t.begin();
		for(int j=id;j<t.size()-1;j++)
			t[j]=0;
	}
	for(int i=0;i<t.size();i++)
		ans[t[i]]++;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		func(i,n,m);
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
