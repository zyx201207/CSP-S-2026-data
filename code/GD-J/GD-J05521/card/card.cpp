#include<iostream>
#include<vector>
using namespace std;
const int MAXN =  500005,MAXM = 300005;
int a[MAXN];
vector<int> v;
int b[MAXM];
void check(int x)
{
	for(int i = 0;i < v.size();i++)
	{
		if(v[i] == x)
		{
			while(v.size()-1>i)
				v.pop_back();
			return;
		}
	}
	v.push_back(x); 
}
void f(){
	for(int i = 0;i < v.size();i++)
		b[v[i]]++;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	for(int i = 1;i <= n;i++)
	{
		v.clear();
		for(int j = i;j <= n;j++)
		{
			check(a[j]);
		}
		f();
	}
	for(int i = 1;i <= m;i++)
		cout<<b[i]<<' ';
	return 0;
}
