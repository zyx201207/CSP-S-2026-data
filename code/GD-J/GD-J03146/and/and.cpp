#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m,ans,ans2;
struct ccj{
	int a,k;
}s[200005];
void f_2(int x,int s_i)
{
	int sum=0;
	string st="";
	while(x>0)
	{
		if(x%2==1)
		{
			sum++;
		}
		st=st+to_string(x%2);
		x=x/2;
	}
	s[s_i].k=sum;
}
bool cmp(ccj x,ccj y)
{
	return x.a>y.a;
}
bool cmp2(ccj x,ccj y)
{
	return x.k>y.k;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a;
		f_2(s[i].a,i);
	}
	sort(s+1,s+n+1,cmp);
	ans=s[1].a;
	for(int i=2;i<=m;i++)
	{
		ans=ans&s[i].a;
	}
	sort(s+1,s+n+1,cmp2);
	ans2=s[1].a;
	for(int i=2;i<=m;i++)
	{
		ans2=ans2&s[i].a;
	}
	cout<<max(ans,ans2);
	return 0;
}
