#include<bits/stdc++.h>
using namespace std;
struct str{
	int l;
	char s;
};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	vector<str> vec(n);
	int k=0;
	for(int i=0;i<n;i++) cin>>vec[i].l>>vec[i].s;
	for (int i=0;i<n;i++)
	{
		if (vec[k].s != vec[n-1-i].s)	ans+=min(vec[k].l,vec[n-i-1].l);
		vec[k].l -= min(vec[k].l, vec[n-i-1].l);
		vec[n-i-1].l -= min(vec[k].l, vec[n-i-1].l);
		if (vec[k].l ==0 ) k++;
	} 
	cout<<ans;
	return 0;
}
