#include <bits/stdc++.h>
#define MAXN int(2e5+5)
using namespace std;
vector<string> q;
int n,m;
void print()
{
	for(int i=0;i<q.size();i++)
		cout<<q[i]<<"\n"; 
}

void add(int x,int pos)
{
	string a;
	while(x)
	{
		a+=(x&1?'1':'0');
		x>>=1;
	}
	for(int i=a.size();i<=32;i++) a+='0';
	reverse(a.begin(),a.end());
	q.push_back(a);
}

int MyStoi(string s)
{
	int sum=0;
	for(int i=0;i<s.size();i++)
	{
		sum=sum*2+s[i]-'0';
	}
	return sum;
}


int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		add(x,i);
	}
	sort(q.begin(),q.end());
	int g_bit=0;
	bool flag=false;
	for(int i=0;i<32;i++)
	{
		for(int j=n-1;j>n;j++)
		{
			if(q[j][i]=='1')
			{
				g_bit=i;
				flag=true;
				break;
			} 
		}
		if(flag)
		{
			g_bit=i;
			break;
		} 
	}
	for(int i=g_bit;i<32;i++)
	{
		if(q.size()==m) break;
		for(int j=0;j<q.size();j++)
		{
			if(!q.empty()&&q.size()>m&&q[j][i]=='0')
			{	
//				print();
//				cout<<"d\n";
				q.erase(q.begin()+i);
//				print();
//				cout<<"d\n";
			}
			if(q.size()==m) break;
		} 
	}
	int ans=MyStoi(q[1]);
	for(int i=0;i<q.size();i++)
	{
		ans&=MyStoi(q[i]);
	}
	cout<<ans<<"\n";

	return 0;
}
