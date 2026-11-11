#include <bits/stdc++.h>
using namespace std;
int n;
long long cnt;
struct node
{
	long long z;
	string zm;
}w[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int r = 1,l = n;
	for(int i = 1;i<=n;i++) cin>>w[i].z>>w[i].zm;
	while(l != r)
	{
		
		int a = min(w[r].z,w[l].z);
		if(w[r].zm == w[l].zm)
		{
			w[r].z-=a;
		    w[l].z-=a;
		}
		else
		{
			cnt+=a;
			w[r].z-=a;
			w[l].z-=a;
		}
		if(w[r].z == 0) r++;
		else l--;
	}
	cout<<cnt;
	return 0;
}
