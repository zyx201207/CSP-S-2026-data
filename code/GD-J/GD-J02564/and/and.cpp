#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2e5+5; 
string z2(int n)
{
	string s1;
	int m=n;
	while(m)
	{
		if(m%2==0)
		{
			s1+='0';
			m/=2;
		}
		
		else
		{
		  s1+='1';
		  m-=1;
		  m/2;	
		}
	}
	reverse(s1.begin(),s1.end());
	return s1;
}    
int n,m,a[M];                          
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	 cin>>n>>m;
	 for(int i=1;i<=n;i++) cin>>a[i];
	 cout<<a[3];
	return 0;
}
