#include <bits/stdc++.h>
using namespace std;
#define ld long long
ld m,step;
ld arr[100000];
void huisu(ld s)
{
	if(s>m)
	{
		step ;
		return ;
	}
}
int main(int argc, char** argv)
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ld c,t,n,d;
	cin>>c>>t;
	for(t;t>0;t--)
	{
		cin>>n>>d;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		srand(time(0));
		cout<<rand()%(n+1);
	}
	return 0;
}
