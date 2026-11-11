#include <bits/stdc++.h>
using namespace std;

const int N=200005;
int n,k,a[N],maxx[N],num=1;
bool ok;

void fast()
{
	ios::sync_with_stdio(false);
	  cin.tie(0);
	  cout.tie(0);
}

int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	fast();
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=num;j>=1;j--)
		{
			if(a[i]>=maxx[j])
			{
				swap(maxx[j],maxx[j+1]);
				swap(maxx[j],a[i]);
				ok=true;
			}
			if(ok)
			{
				num++;
				ok=false;
			}
			else
			  break;
		}
	}
	cout<<maxx[k];
	
	return 0;
}
