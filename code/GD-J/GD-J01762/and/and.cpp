#include<bits/stdc++.h>

using namespace std;

int n,a[200010],dp[200010][32],m,ans=pow(2,32)-1,l[200010];
bool f[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	
	for(int i=0;i<n;i++)
	{
		l[i]=a[i];
		for(int j=31;j>=0;j--)
		{
			if(a[i]>=pow(2,j)){
				a[i]-=pow(2,j);
				dp[i][j]=1;
			}
		}
	}
	
	for(int i=31;i>=0;i--)
	{
		int cnt=0;
		for(int j=0;j<n;j++){
			if(!f[j]) cnt+=dp[j][i];
		}
		if(cnt>=m){
			for(int j=0;j<n;j++){
				if(dp[j][i]==0) f[j]=true;
			}
		}
	}
	
	for(int i=0;i<n&&m>0;i++){
		if(f[i]==false){
			ans=ans&l[i];
			m--;
		}
	}
	cout << ans << endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
 } 
