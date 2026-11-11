#include <bits/stdc++.h>
using namespace std;
#define ios ios::sync_with_stdio(false);cin.tie(nullptr);
#define int long long
const int N= 2e5+10;
int n,m;
int a[N];
int ans;
map<int,string> key;
bool cmp(int x,int y)
{
	return x>=y;
}
void change(int in)
{
	string x="";
	while(in)
	{
		x+=char(in%2+'0');
		in/=2;
	}
	key[key.size()+1]=x;
}
int And(int in1,int in2)
{
	string res="";
	string x="",y="";
	while(in1)
	{
		x+=char(in1%2+'0');
		in1/=2;
	}
	while(in2)
	{
		y+=char(in2%2+'0');
		in2/=2;
	}
	int p=x.length()-y.length();
	if(p<0)
	{
  		for(int i=1;i<-p;i++) x.insert(0,"0");
	}
	else if(p>0)
	{
		for(int i=1;i<p;i++) y.insert(0,"0");
	}
	int len=x.length();
	for(int i=len-1;i>=0;i--)
	{
		if(x[i]==y[i])
		{
			res+='1';
		}
		else
		{
			res+='0';
		}
	}
	int sum=0;
	for(int i=0;i<len;i++)
	{
		sum+=pow(2,len-i-1)*(res[i]-'0');
	}
	return sum;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++)
	{
		ans=And(ans,a[i]);
	}
	cout<<ans;
}
signed main()
{
	ios;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	solve();
	return 0;
}

