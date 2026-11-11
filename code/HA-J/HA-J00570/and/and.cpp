#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ni[200005]={};
long long ans;
bool work1(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r","stdin");
	freopen("and.out ","w","stdout");
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>ni[i];
	}
	sort(ni+1,ni+1+n,work1);
	for(int i=2;i<=n;i++)
	{
		ni[i]=ni[i-1] and ni[i];
	}
	cout<<ni[m];
	return 0;
} 
