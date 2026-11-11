#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, a[200005], ans;
string s[200005];
bool ok[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i], ok[i]=1;
	for(int i=1; i<=n; i++)
	{
		s[i]=bitset<32>(a[i]).to_string();
//		cout<<s[i]<<'\n';
	}
	for(int i=1; i<=32; i++)
	{
		set<int> st;
		int cnt=0;
		for(int j=1; j<=n; j++)
		{
			if(ok[j])
				if(s[j][i]=='1') cnt++, st.insert(j);
		}
//		cout<<"cnt: "<<cnt<<"   ";
		if(cnt>=m)
		{
//			cout<<"第"<<i<<"位, "<<"留"<<cnt<<"个\n"; 
			for(int i=1; i<=n; i++) if(!st.count(i)) ok[i]=0;
		}
		else
		{
//			cout<<"第"<<i<<"位, "<<"全部保留。\n"; 
		}
	}
	int flag=0;
	for(int i=1; i<=n; i++)
	{
		if(ok[i])
		{
			ans = a[i]; flag=i; break;
		}
	}
	for(int i=flag; i<=n; i++)
	{
		if(ok[i]) ans&=a[i];
	}
	cout<<ans<<'\n';
	return 0;
}

