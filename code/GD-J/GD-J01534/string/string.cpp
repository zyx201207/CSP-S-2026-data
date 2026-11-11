#include<bits/stdc++.h>
using namespace std;
long long n=0;
double sum=0,ans=0,k=0,a[200005];
char c[200005];
double add(double a,double b)
{
	if(a-b<0) return 0;
	else return a-b;
}
int main()
{	
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	//scanf("%lld",&n);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
	   cin>>a[i]>>c[i];
	}
	k=a[n];
	for(int i=1,j=n;i<=j;i++)
	{
	    sum=(long long)(sum+a[i]);
	    ans=(long long)(ans+a[i]);
	    if(k==0) k=a[j];
	    while(ans!=0&&j-1>=i)
	    {
	       	    
	       	if(c[i]==c[j]) sum=(long long)(sum-k);
	       	else 
	       	{
	       	    if(ans<k) 
				{
					k=(long long)(k-ans);
					ans=0;
					break;
				}
				else ans=(long long)(ans-k);  
			}
			if(ans!=0)
		    j--;
		}
	}
	//printf("%lld",(long long)add(sum,ans));
	cout<<(long long)add(sum,ans);
	return 0;
 } 
 /*
4 
3 a
2 b 
3 c
1 b
 
 
 
3
2 a
2 b
1 c
6 1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b
 */
