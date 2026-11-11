#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6;
int sum[50];
int num[N][50];
vector<int>vect;
void init(int tmp,int x)
{
	int cnt=0;
	while(x)
	{
		if(x&1)
		{
			num[tmp][cnt]=1;
			sum[cnt]++;
		}
		cnt++;
		x>>=1;
	}
}
void solve(int x)
{
	for(int i=0;i<=31;i++)sum[i]=0;
	vector<int>newv;
	for(auto i:vect)
	{
		if(num[i][x]==1)
		{
			newv.push_back(i); 
			for(int j=0;j<=31;j++)if(num[i][j])sum[j]++;
		}
	}
	vect=newv;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x ;cin>>x;
		vect.push_back(i);
		init(i,x);
//		for(int j=0;j<=30;j++)cout<<num[i][j];
//		cout<<endl;
	}
	string str="";
	for(int i=31;i>=0;i--)
	{
		if(sum[i]==m)
		{
			solve(i);
			break;
		}
		else if(sum[i]>m)
		{
			solve(i);
			str+='1';
		}
		else if(sum[i]<m)
		{
			i--;
			str+='0';
		}
	}
//	for(auto tmp:vect)cout<<tmp<<" ";
//	cout<<endl;
//	for(int i=0;i<=30;i++)cout<<sum[i]<<" ";
//	cout<<endl;
	int x=1;int res=0;
	for(int i=0;i<=31;i++)
	{
		if(sum[i]>=m)res+=x;
		x<<=1;
	}
	cout<<res;
}
/*
5 3 
31 
3
1
15 
7

*/
