#include <bits/stdc++.h>
using namespace std;
const int maxn = 2*1e5+100;

struct node{
	int len;
	char a;
}a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 

    int n;
    cin>>n;
    if(n==1) cout<<"0";
    long long l = 0;
    long long sum = 0;
    for(int i = 1 ;i <= n ;i++)
    {
    	cin>>a[i].len>>a[i].a;
	}
	if(n==2)
	{
		if(a[1].a==a[2].a)
		{
			cout<<"0";
			return 0;
		}
		else
		{
			cout<<min(a[1].len,a[2].len);
		}
	}
	for(int i = 1;i <= n ;i++)
	{
		
		l+=a[i].len;
		
	}
	for(int  i = 1 ; i <= n ;i++)
	{
		if(a[i].len == a[n+1-i].len&&a[i].a == a[n+1-i].a)
		{
			continue;
		}
		else 
		{
			a[n-i+1].a = a[i].a;
			sum+=min(a[i].len,a[n+1-i].len);
		}
	 } 
	cout<<sum;
	
	

	
	return 0;
 } 
