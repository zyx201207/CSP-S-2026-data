#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
unordered_set<int> st;
bool cmp(int x,int y) {return x>y;}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) st.insert(i);
	for(int i=(int)log2(a[1]);i>=0;i--)
	{
		int t=(1<<i);
		vector<int> newsub;
		for(auto j:st)
		{
			if((a[j]|t)==a[j])
			{
				newsub.push_back(j);
			}
		}
		if(newsub.size()>=m)
		{
			st.clear();
			for(auto j:newsub)
			{
				st.insert(j);
				a[j]-=t;
			}
			ans|=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
