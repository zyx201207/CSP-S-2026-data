#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n;
struct zimu
{
	int num;
	char c;
}arr[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i].num>>arr[i].c;
	}
	int i=1,j=n,ans=0;
	int a=arr[i].num,ac=arr[i].c,b=arr[j].num,bc=arr[j].c;
	while(i<j)
	{
		if(a>=b)
		{
			a-=b;
			if(ac!=bc)ans+=b;
			j--;
			b=arr[j].num,bc=arr[j].c;
		}
		else if(b>a)
		{
			b-=a;
			if(ac!=bc)ans+=a;
			i++;
			a=arr[i].num,ac=arr[i].c;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
