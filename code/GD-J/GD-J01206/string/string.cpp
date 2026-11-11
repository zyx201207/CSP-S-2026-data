#include <bits/stdc++.h>
using namespace std;

long long n,ans,num,m,sum[200005],maxx;
char a;

void fast()
{
	ios::sync_with_stdio(false);
	  cin.tie(0);
	  cout.tie(0);
}

int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	fast();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>a;
		sum[int(a-'a')+1]+=m;
		maxx=max(maxx,sum[int(a-'a')+1]);
		num+=m;
	}
	if(n==maxx)
	{
		cout<<"0";
		return 0;
	}
	if(num%2==1)
	  cout<<num-maxx-1;
	else
	  cout<<num-maxx;
	
	
	
	return 0;
}
