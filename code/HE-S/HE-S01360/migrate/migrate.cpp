#include<bits/stdc++.h>
using namespace std;
long long x[2000100],d;//remember d is long long!!!
int a[2000100],top;
int n;
int check(int l,int r)
{
	int sum=0;long long nowl=0;
	top=0;a[++top]=l;
	for(int i=l+1;i<=r;i++)
	{
		if(nowl+x[i]-x[i-1]>d)
		{
			if(x[i]-x[i-1]>d)return 0;
			//lst=i;//add this    delite this
			a[++top]=i-1;
			sum++;
			nowl=0;
		}
		nowl+=x[i]-x[i-1];
	}
	a[++top]=r;
	return sum+1;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				int f=check(i,j),flag=0;
				if(f==0)continue;
				
//				cout<<i<<' '<<j<<':';
//				for(int k=1;k<=top;k++)cout<<a[k]<<(k==top?'\n':' ');
				
				for(int k=2;k<=top-1;k++)
				{
					if(a[k-1]<a[k]-1 && x[a[k+1]]-x[a[k]-1]<=d && x[a[k]-1]-x[a[k-1]]<=d)flag++/*,cout<<"-"<<a[k]<<"-"*/;
					if(a[k+1]>a[k]+1 && x[a[k+1]]-x[a[k]+1]<=d && x[a[k]+1]-x[a[k-1]]<=d)flag++/*,cout<<"+"<<a[k]<<"+"*/;
					//not if(a[k-1]!=a[k]-1 && x[a[k+1]]-x[a[k]-1]<=d && x[a[k]-1]-x[a[k-1]]<=d)flag++;
					//add other election (not != !!!!!
					if(a[k-1]<a[k]-2 && x[a[k+1]]-x[a[k]-2]<=d && x[a[k]-2]-x[a[k-1]]<=d)flag++/*,cout<<"--"<<a[k]<<"--"*/;
					if(a[k+1]>a[k]+2 && x[a[k+1]]-x[a[k]+2]<=d && x[a[k]+2]-x[a[k-1]]<=d)flag++/*,cout<<"++"<<a[k]<<"++"*/;
					if(flag==2)goto endd;
				}
				if(flag==1)ans++;
				endd:;
			}
		cout<<ans<<endl;
	}
}
//5:00 have idea to solve it with 24pts
//5:35 init error wtf it is (5:48 in fact,is long long lead to error
//5:55 第二题（s u b w a y） 中的样例解释请忽略公式中的变量部分，以文字叙述部分与公式中的数值部分为准  (hyw 
//? is OK 
