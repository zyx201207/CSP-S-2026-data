#include<bits.stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	struct ci,x;
	int n,ai,m=0,y=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> ai >> ci;
		for(int j=1;j<=ai;j++)
		{
			x+=ci;
		}
	}
	for(int i=1;i<=x.length()/2;i++)
	{
		if(x[i]==x[x.length()-i])
		{
			m++;
		}
		else
		{
			y++;
		}
	}
	cout << y;
}
