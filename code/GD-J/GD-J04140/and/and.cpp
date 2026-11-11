#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
long long AND(int x,int y)
{
	string X="",Y="",X1="",Y1="";
	if(x<y)swap(x,y);
	for(int i=x;i>0;i/=2)
	{
		if(i%2==1)X1+='1';
		else X1+='0';
	}
	for(int i=y;i>0;i/=2)
	{
		if(i%2==1)Y1+='1';
		else Y1+='0';
	}
//	int SX1=X1.size(),SY1=Y1.size();
//	for(int i=1;i<=SX1-SX2;i++)Y1+='0';
	for(int i=X1.size()-1;i>=0;--i)
	{
		X+=X1[i];
	}
	for(int i=Y1.size()-1;i>=0;--i)
	{
		Y+=Y1[i];
	}
	string sl;
	long long ans=0;
	int cha=X.size()-Y.size();
	for(int i=0;i<Y.size();++i)
	{
		if((Y[i]==X[i+cha])&&(X[i+cha]=='1'))sl+='1';
		else sl+='0'; 
	}
	for(int i=sl.size()-1,j=0;i>=0;i--,j++)
	{
		if(sl[i]=='1')ans+=pow(2,j);
		//cout<<sl[i]<<" "<<j<<"\n";
	}
	//cout<<sl<<"\n";
	return ans;
}
map<long long,int> cnt;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	long long maxx=-1;
	for(int i=1;i<=n;++i)
	{
		map<long long,int> c;
		for(int j=i+1;j<=n;++j)
		{
			c[a[j]]++;
			if(c[a[j]]==1)
				cnt[AND(a[i],a[j])]++;
			maxx=max(maxx,AND(a[i],a[j]));
		}
	}
	for(int i=maxx;i>=0;i--)
	{
		if(cnt[i]==m)
		{
			cout<<i;
			return 0;
		}
	}
}
/*
4 2
3 15 12 12
*/
