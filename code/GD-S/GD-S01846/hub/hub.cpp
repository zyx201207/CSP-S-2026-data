#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1,a,b;i<=n;i++)scanf("%d%d",&a,&b);
		cout<<n-k<<endl;
	} 
	return 0;
}

