#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;
deque<int> w;deque<char> c;
long long res=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int w1;
		char c1;
		cin>>w1>>c1;
		w.push_back(w1);
		c.push_back(c1);
	}
	while(w.size()&&w.size()!=1)
	{
		int n1=w.front();
		int n2=w.back();
		char c1=c.front();
		char c2=c.back();
		if(n1>n2)
		{
			w.pop_back();
			c.pop_back();
			w.pop_front();
			w.push_front(n1-n2);
		}
		else if(n1<n2)
		{
			w.pop_front();
			c.pop_front();
			w.pop_back();
			w.push_back(n2-n1);
		}
		else 
		{
			w.pop_back();
			w.pop_front(); 
			c.pop_back();
			c.pop_front(); 
		}
		if(c1!=c2)res+=min(n1,n2);
	}
	cout<<res;
}
