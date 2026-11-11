#include<bits/stdc++.h>
using namespace std;
struct node{
	long long n;
	char a;
};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    node b[200005];
	int m;
	long long sum=0,ans=0,k=0;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i].n>>b[i].a;
		sum+=b[i].n;
	}
	int mid=1+(m+1-1)/2;
	long long l=1,r=m;
	while(l!=mid && r!=mid)
	{
		if(b[l].a!=b[r].a)
		{
			long long s=b[l].a>=b[r].a?b[l].n:b[r].n;
			ans+=s-k;
			l++;
			r--;
			k=s-k;
			if(b[l].a==b[r].a)k=0;
		}
	}
	cout<<ans;
	return 0;
}
