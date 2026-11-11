#include <bits/stdc++.h>
using namespace std;
int n,k;

struct rc
{
	int u,v;
}rac[1000005];

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<n;i++) cin>>rac[i].u>>rac[i].v;
	return 0;
}

