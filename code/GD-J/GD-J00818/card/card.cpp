#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+100;
long long n,m,a[maxn],cnt,maxx=-1;
string s;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int len=s.size();
		int pos=s.find(a[i]);
		if(pos!=-1)
		{
			string ts=sub(pos,len-pos-1);
			s-=ts;
		}
		
		-static-libgcc
	}
}
