#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long tongji[500005];
int ansn[500005];
long long jis(int num,long long k)
{
	return tongji[num]- (a[num]-a[k]) + (num-k)*(a[num+1]-a[num]);
}
int main()
{
	freopen("crystal3.in","r",stdin);
	freopen("crystal10.out","w",stdout);
	long long m,n;
	cin>>n>>m;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
//	for(int i=0;i<n;i++)
//	{
//		cout<<i+1<<" "<<a[i]<<endl;
//	}
	long long k=0;
	for(int i=1;i<n;i++)
	{
		int cha=a[i]-a[i-1];
		tongji[i]=tongji[i-1]+(i-k)*cha;
		if(i+1>=n) 
		{
			if(tongji[i]<=m)
			{
				ans=i-k+1;
//				cout<<tongji[i]<<endl;
				//cout<<ans<<endl;
			}
			break;
		}
		//cout<<k<<" "<<tongji[i]<<" cha "<<a[i]-a[k]<<" jcha "<<(i-k)*(a[i+1]-a[i])<<" "<<jis(i,k)<<" "<<i<<endl;
		//cout<<tongji[i]<<" "<<cha<<endl;
		
		if(tongji[i]<=m||jis(i,k)<=m)
		{
			ans=i-k+1;
			//cout<<ans<<endl;
		}
		if(jis(i,k)<=tongji[i])
		{
			i+=1;
			tongji[i]=jis(i-1,k);
			//cout<<tongji[i]<<" "<<i<<endl;
			k+=1;
		}
	}
	
	if(a[ans+k-1]==a[ans+k])
	{
		ans+=1;
	}
	int s=ans;

	for(int i=k;i>=1;i--)
	{
		if(tongji[s+k-1]+(a[s+k-1]-a[i-1])<=m)
		{
			//cout<<s+k-1<<" "<<tongji[s+k-1]+(a[s+k-1]-a[i-1])<<endl;
			tongji[s+k-1]+=a[s+k-1]-a[i-1];
			ans+=1;
		}

	}
	
	if(ans==0) {cout<<n;return 0;}
	cout<<ans;
	return 0;
}
