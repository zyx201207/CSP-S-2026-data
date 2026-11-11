#include<bits/stdc++.h>
#define N 200010
#define int long long
using namespace std;
int n,len,ans;
int ca[N],a;
string b;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b[i];
		ca[i]=a;
	}
//	cout<<b<<'\n';
	for(int i=1,j=n;i<j;)
	{
//		cout<<'-'<<i<<' '<<j<<'\n';
		if(!ca[i]) 
		{
			i++;
			continue;
		}
		if(!ca[j]) 
		{
			j--;
			continue;
		}
		
		if(b[i]==b[j])
		{
			if(ca[i]==ca[j])
			{
				i++,j--;
			}
			else if(ca[i]>ca[j])
			{
				j--;
	//			cout<<ca[i]<<' '<<ca[j]<<'\n';
				ans+=ca[i]-ca[j];
				ca[i]-=ca[j];
			}
			else if(ca[i]<ca[j])
			{
				i++;
	//			cout<<ca[i]<<' '<<ca[j]<<'\n';
				ans+=ca[j]-ca[i];
				ca[j]-=ca[i];
			}
		}
		else
		{
			if(ca[i]<ca[j])
			{
				i++;
//				cout<<ca[i]<<' '<<ca[j]<<'\n';
				ans+=ca[i];
				ca[j]-=ca[i];
			}
			else if(ca[i]>ca[j])
			{
				j--;
//				cout<<ca[i]<<' '<<ca[j]<<'\n';
				ans+=ca[j];
				ca[i]-=ca[j];
			}
			else if(ca[i]==ca[j])
			{
				ans+=ca[i];
				ca[i]=0,ca[j]=0;
				i++,j--;
			}
		}
	}
	cout<<ans;
	return 0;
}

/*
7
1 a
3 c
2 d
1 f
2 c
1 e
1 a

8
1 a
2 c
1 d
1 a
1 b
1 a
2 c
2 a
*/ 
