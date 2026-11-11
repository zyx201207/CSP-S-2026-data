#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
long long ans=0;
void work1(int now,int tot,long long res)
{
	if(tot==m)
	{
		ans=max(ans,res);
		return ;
	}
	for(int i=now+1;i<=n;i++)
	{
		work1(i,tot+1,(res&a[i]));
	}
	return ;
}
void work2()
{
	sort(a+1,a+n+1);
	cout<<a[n]<<"\n";
	return ;
}
void work3()
{
	int ans=a[1];
	for(int i=1;i<=n;i++)
	{
		ans&=a[i];
	}
	cout<<ans<<"\n";
	return ;
}
int d[105];
//int b[]
void work5()//来不及写了啊啊啊 
{
//    for(int i=1;i<=n;i++)
//    {
////    	int top=0,x=a[i];
////    	while(x)
////    	{
////    		if(x%2==1)
////    		{
////    			d[top]++;
////			}
////			top++;
////			x/=2;
////		}
//	}	
	sort(a+1,a+n+1); 
	int ans=a[1];
	for(int i=n;i>=1;i--)
	{
		ans&=a[i];
	}
	cout<<ans<<"\n";
	return ;
	
}
bool cka()
{
	for(int i=1;i<=n;i++)
	{
		bool f=0;
		int x=a[i]+1;
		for(int j=0;j<=30;j++)
		{
			if(1LL*pow(2,j)==x)
			f=1;
		}
		if(f==0)return 0;
	}
	return 1;
}
void work6()
{
	sort(a+1,a+n+1);
	int ans=a[n];
	for(int i=n;i>=n-m+1;i--)
	{
		ans&=a[i];
	}
	cout<<ans<<" ";
	return ;
}
bool ckb()
{
	for(int i=1;i<=n;i++)if(a[i]!=i-1)return 0;
	return 1;
}
void work7()
{
	sort(a+1,a+n+1);
	int ans=a[n];
	for(int i=n;i>=n-m+1;i--)
	{
		ans&=a[i];
	}
	cout<<ans<<" ";
	return ;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	} 
	if(n<=20)
	{
		work1(0,0,pow(2LL,31LL)-1LL);
		cout<<ans<<"\n";
		return 0;
	}
	else if(m==1)work2();
	else if(m==n)work3();
	else if(m==2)
	{
		work1(0,0,pow(2LL,31LL)-1LL);
		cout<<ans<<"\n";
		return 0;
	}
	else if(m==n-1)work5();
	else if(cka())work6();
	else if(ckb())work7();
	else 
	{
		work1(0,0,pow(2LL,31LL)-1LL);
		cout<<ans<<"\n";
	}
    return 0;
}
