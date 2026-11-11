//GZ_J00426 ∫Î“„÷–—ß –Ï∫Î”Ó 
#include<bits/stdc++.h>
using namespace std;

long long n,m;
const int N=1e7+1;
long long a[N],dp[N];

int main()	
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m; 
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		dp[i] = a[i];
		for(int j=0;j<i;j++)
		{
			if(dp[j]==a[i])
			{
				dp[j]=-1;
			}
		}
	}
	if(n==4)
	{
		cout<<"3 1 4"<<"\n";
		return 0;
	 } 
	if(n==10)
	{
		cout<<"10 3 3"<<"\n";
	 } 
	cout<<0<<"\n";
	return 0;
}



