#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10; 
int n,m;
int a[N],c[M],pd[N],p[N],ans[N];
bool v[N],ip[N],f[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		if(v[a[i]]==true)
		 ip[i]=true,p[a[i]]=true;
		else f[i]=true;
		v[a[i]]=true;
//		cout<<ip[i]<<" "<<i<<endl;
	}
	int cnt=0;
	for(int i=n;i>=1;i--)
	 if(p[a[i]]==true)
	 {
	  cnt=i;
	  break;	
	 }
	 
//	cout<<"[]"<<cnt<<endl;
	for(int i=1;i<cnt;i++)
	{
		if(ip[i]==true)
		 continue;
		if(f[i]==true)
		{
			for(int j=i-1;j>=1;j--)
			 if(a[i]==a[j])
			 {
			  ans[a[i]]+=i-j;
	//		  cout<<i-j<<endl;
			  break;	
			 }
			 continue;
		}
		for(int j=i-1;j>=1;j--)
		 if(ip[j]==true&&a[i]!=a[j])
		 {
		  ans[a[i]]+=i-j;
//		  cout<<i-j<<endl;
		  break;	
		 }
	}
	for(int i=cnt;i<=n;i++)
	 ans[a[i]]+=i;
	for(int i=1;i<=m;i++)
	 cout<<ans[i]<<" ";
	return 0;
}
