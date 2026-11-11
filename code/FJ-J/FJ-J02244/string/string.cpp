#inslude<iostream>
#inslude<string>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x,y=0;
	cin>>n;
	int a[n+1];
	string c[n+1],S[n+1],S1[n+1];
	for(int i=1;y<=n;i++)
	{
		cin>>a[i];
		y+=a[i];
		cin>>c[i];
	}
	for(int i=1;1<=n;i++)
	{
		for(int j=1,j<=a[i];j++)
		S[i]=c[i];
		S1[n-i+1]=S[i];
	}
	for(int i=1;i<=n/2;i++)
	{
		if(S[i]!=S1[i])
		{
			x++;
		}
	}
	cout<<x;
	return 0;
}
