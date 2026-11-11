#include<bits/stdc++.h>
using namespace std;
struct wn
{
	long long m;
	char a;
}; 
wn c[200005];
int main()
{
	int x=1;
	while(x<10)
	{
		cout<<x;
		x++;
	}
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i].m>>c[i].a;
	}
	return 0;
} 

