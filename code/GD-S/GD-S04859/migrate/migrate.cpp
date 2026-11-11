#include<bits/stdc++.h>
using namespace std;
long long c,t;
void slove(){
	long long n,d;
	cin>>n>>d;
	vector<long long> y(n);
	for(int i=1;i<=n;i++)
	{
		cin>>y[i];
	}
	vector<long long> dp(n,0);
	for(int i=2;i<=n;i++)
	{
		if(y[i]-y[i-1]<=d)
		{
			dp[i]+=dp[i-1]+dp[i]+1;
		}
	}
	cout<<0<<endl;
	
	
	
}
int main(){
     freopen("migrate.in","r",stdin);
     freopen("migrate.out","w",stdout);
     ios::sync_with_stdio(false);
     cin.tie(nullptr),cout.tie(nullptr);
    cin>>c>>t;
    while(t--)
    {
    	slove();
    	
	}
    
    
    
	  return 0;
 } 
