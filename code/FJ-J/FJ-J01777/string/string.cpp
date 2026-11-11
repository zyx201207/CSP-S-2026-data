#include <bits/stdc++.h>
using namespace std;
char ch[200005];
int gs[200005];
long long sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	//cout<<n<<endl;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%s",&gs[i],&ch[i]);
		//cout<<gs[i]<<" "<<ch[i]<<endl;
	}
	if(!n&1)
	{
		for(int i=1;i<=n/2;i++)
		{
			int nn=n-i+1;
			if(ch[i]!=ch[nn])
			{
				sum+=gs[i]+gs[nn];
			}
			else {
				if(gs[i]==gs[nn]) continue;
				else sum+=gs[i]+gs[nn];
			} 
		}
	} 
	cout<<sum;
	return 0;
}
