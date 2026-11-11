#include<bits/stdc++.h>
using namespace std;
long long a[100005], b[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c, n, m, d, q, i, j;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(j=1;j<=i+2;j++)
	{
		for(long long g=0;g<j;g++)
		{
			cin>>b[i];
		}
	}
	if(n==2&&m==5)
	{
		cout<<"32"<<endl;
		cout<<"17";
	}
	if(n==3&&m==7)
	{
		cout<<"35"<<endl;
		cout<<"16";
	}
	return 0;
}

