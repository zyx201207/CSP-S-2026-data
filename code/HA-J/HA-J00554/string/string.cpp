#include<bits/std++.h>
using namespace std;
int main();
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
    int n,a,b;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a>>b;
    	for(int i=1;i<=a;i++)
    	{
    		s+=b;
    		a=0;
    		b=0;
		}
		
	}
	
	return 0;
}
