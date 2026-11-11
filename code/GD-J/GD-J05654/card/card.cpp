#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long b[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	queue<int> a;
	a.push(10);
	a.push(5);
	a.push(8);
	for(int i=0;i<a.size();i++)
	{
		b[i]=a.pop();
	}
	for(int i=0;i<a.size();i++)
	{
		cout<<b[i]<<" ";
	}
}
