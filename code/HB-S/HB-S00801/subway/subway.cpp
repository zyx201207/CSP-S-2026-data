#include<bits/stdc++.h>
using namespace std;
const int M=500005;
long long c,n,m,d,q,u,w,u11,t11;
long long a[M];
struct node
{
	int u1,v1;
}b[100005];
int book[501];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>u11>>t11;
		book[u11]=t11;
	}
	for(int i=1;i<=p;i++)
	{
		cin>>b[i].u1>>b[i].v1;
	}
	for(int i=1;i<=p;i++)
	{
		int one=rand()%m+1,two=rand()%m+1,three=rand()%m+1,fl=rand()%3;
		if(fl==2)cout<<a[one]+book[one]+a[two]+book[two]+a[three]+book[three]<<endl;
		if(fl==1)cout<<a[one]+book[one]+a[two]+book[two]<<endl;//QAQ I can not only do it but also do it for special-A
	}
	return 0;
}
//I'm eye flower chat untidy
