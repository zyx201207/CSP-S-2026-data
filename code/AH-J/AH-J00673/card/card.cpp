#include <iostream>
#include <stack>
#include <algorithm>
#define int long long
#define mmx 500001
#define fo(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
stack<int> stk;
int a[mmx],f[mmx],s[mmx],t[mmx];
signed main()
{
	ios::sync_with_stdio(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	fo (i,1,n) cin>>a[i];
	cout<<"ee";
	fo (i,1,n)
	{
		fill(f+1,f+n+1,0);
		fo (j,i,n)
		{
			if (f[a[j]]==1)
				while (stk.empty()==0)
				{
					cout<<"remove:"<<a[j]<<"\n";
					if (stk.top()!=a[j]) stk.pop();
					else {stk.pop(); break;}
				}
			cout<<"push:"<<a[j]<<"\n";
			stk.push(a[j]);
			f[a[j]]=1;
		}
		fill(s+1,s+m+1,0);
		cout<<"stk:";
		while (stk.empty()==0)
		{
			cout<<stk.top()<<" ";
			s[stk.top()]=1;
			stk.pop();
		}
		cout<<"\n";
		fo (j,1,m) t[j]+=s[j];
		fo (i,1,m) cout<<s[i]<<" ";
		fo (i,1,m) cout<<t[i]<<" ";
		cout<<"\n\n";
	}
	fo (i,1,m) cout<<t[i]<<" ";
	return 0;
}
