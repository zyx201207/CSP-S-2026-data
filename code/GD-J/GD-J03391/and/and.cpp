#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005][50],s[50][200005],sum=0,ans=1;
int main(){
	freopen("and.in","r",stdin);
	feopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0];
		int x=a[i][0],t=1;
		while(x)
		{
			if(x%2==1)
			{
				a[i][t]=1;
				s[t][0]++;
				s[t][s[t][0]]=i;
			}
			t++;
			x/=2;
		}
	}
	for(int i=35;i>=1;i--)
	{
		if(s[i][0]>=m){
			n=i;
			sum=i;
			break;
		}
	}
	//if(s[sum][0]==m)
	//{
		ans=a[s[sum][1]][0];
		//cout<<ans<<" ";
		for(int i=2;i<=s[sum][0];i++)
		{
			//cout<<ans<<" ";
			ans=((ans) & (a[s[sum][i]][0]));
			//cout<<a[s[sum][i]][0]<<" ";
			//cout<<endl;
		}
		cout<<ans;
		return 0;
	//}
	if(!sum)ans=0;
	while(sum--)
		ans*=2;
	cout<<sum;
	/*
	for(int i=1;i<=s[n][0];i++)
	{
		a[i][0]=;
		int x=a[i][0],t=1;
		while(x)
		{
			if(x%2==1)
			{
				a[i][t]=1;
				s[t][0]++;
				s[t][s[t][0]]=i;
			}
			t++;
			x/=2;
		}
	}
	*/
	return 0;
}
