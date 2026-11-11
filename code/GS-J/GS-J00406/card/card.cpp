#include<bits/stdc++.h> 
using namespace std;
int a[1000000];
int main()
{

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,r;
	string t,c;
	char d,f;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
    }
    for(int i=1; i<=n; i++)
	{
	       for(int j=1; j<=n; j++)
	      {
		         if(a[j]==a[j+1])
		         {
		         	cout<<"990";
				 }
          }
    }
    
	return 0;
}
