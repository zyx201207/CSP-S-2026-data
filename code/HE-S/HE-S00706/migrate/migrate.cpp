#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000006],ans,anss,minn;
void so(int de,int la,int to)
{
	if(la==n)
	{
		
		if(minn>de)
		{
			minn=n;
			ans=0;
		}else if(minn==de){
			ans++;
		}
		return;
	}
	for(int i=la+1;i<=to;i++)
	{
		if(x[i]-x[la]>d)
			break;
		so(de+1,i,to);
	}		
		
}
int main()
{
//	/*
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	*/
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				ans=0;
				minn=INT_MAX;
				so(0,i-1,j);
				if(ans==2)
					anss++;
			}
		}
		cout<<anss<<endl;
	}
	return 0;
}

//ccf makes human headache.
//T1
