#include<bits/stdc++.h>
using namespace std;
unsigned b;
bool cmp(int x,int y)
{
	return (x&b)>(y&b);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a;
	unsigned u=-1;
	vector<int> v;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%d",&a);v.push_back(a);
	}
	for(b=1<<31;b;b>>=1)
	{
		sort(v.begin(),v.end(),cmp);
		if(v[m-1]&b)
		while(((*(v.end()-1))&b)==0)v.erase(v.end()-1);
	}
	for(int i=m;i--;) u&=v[i];
	printf("%d",u);
	return 0;
}
