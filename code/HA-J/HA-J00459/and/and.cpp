#include<bits/stdc++.h>
using namespace std;
bool an[31]={0};
int t[200005];
bool a[200005][31]={0};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxb=0;
	int maxw=0;
	for(int i=1;i<=n;++i)
	{
		int c;
		cin>>c;
		int bw=0;
		int bww=0;
		while(c)
		{
			if(c%2==0) a[i][30-bw]=0;
			else a[i][30-bw]=1;
			c=c/2;
			bw+=1;
		}
		maxb=max(maxb,bw);
		maxw=max(maxw,bww);
	}
//	for(int j=1;j<=n;++j)
//	{
//		for(int i=31-maxb;i<=30;++i)
//		{
//		
//			cout<<a[j][i];
//		}
//		cout<<endl;
//	}
	bool flag=1;
	for(int i=31-maxb,k=1;i<=30;++i,++k)
	{
		for(int j=1;j<=n;++j)
		{
			if(a[j][i]&&(t[j]||flag)) t[j]+=1;
		}
		int ans=0;
		for(int j=1;j<=n;++j)
		{
			if(t[j]==k) ans+=1;
		}
//		cout<<"**"<<i<<" "<<ans<<endl;
		if(ans>=m) flag=0,an[i]=1;
		if(ans<m)  an[i]=0;
	}
	long long aans=0;
//	for(int i=31-maxb;i<=30;++i) cout<<an[i]<<endl;
	for(int i=31-maxb;i<=30;++i)
	{
		aans+=an[i]*pow(2,30-i);
	}
	cout<<aans<<endl; 
	return 0;
}
