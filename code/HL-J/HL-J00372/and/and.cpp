#include<bits/stdc++.h>
using namespace std;
long long a,s,d,f;
int main ()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin  >> a >> s;
	long long qwe[a],we[s][a],x[s],max=0,m=0;
	for(int i=0;i<a;i++)
	{
		cin >> qwe[i];
		if(qwe[i]>max)
		{
			max=qwe[i];
		 } 
	}
	cout<<max;
return 0;
}


