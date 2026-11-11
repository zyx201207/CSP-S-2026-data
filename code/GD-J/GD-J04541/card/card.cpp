#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int cnt=0;
char a[N];
struct node{
	int id;
	string d;
}s[N];
map<int,int> bz;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		if(cnt==m) break;
		if(bz[a[i]]==0)
		{
			bz[a[i]]=1;
			cnt++;
			s[a[i]].id=i;
			s[a[i]].d=a[i];
			int sum=0;
			for(int j=i+1;j<=n;j++)
			{
				s[a[i]].d+=s[j].d;
				j=s[j].id;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		char asd=i;
		cout<<s[asd].d<<endl;
	}
	return 0;
}
