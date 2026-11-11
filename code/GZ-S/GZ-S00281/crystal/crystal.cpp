//GZ-S00281 遵义航天高级中学 罗上 
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
unsigned long long m;
unsigned int n;
long long a[500005];
bool falg[500005];
int ans=0;
int temp;
void dfsh(long long now,int count)
{
	long long *p=find(a,a+n,now);
	if(p==a+n)
	{
		ans=max(ans,count);
		return;
	}
	while(falg[p-a])
	{
		p++;
		if(p==a+n||*p!=now)
		{
			ans=max(ans,count);
			return;
		}
	}
	falg[p-a]=true;
	dfsh(now*2,count+1);
	falg[p-a]=false;
}
void dfsf(int s,int k)
{
	if(k<0&&s)
	{
		return;
	}
	if(!s)
	{
		for(int i=0;i<n;i++)
		{
			falg[i]=true;
			dfsh(a[i],1);
			falg[i]=false;
		}
		return;
	}
	for(int i=0;i<=s;i++)
	{
		a[k]+=i;
		dfsf(s-i,k-1);
		a[k]-=i;
	}
}
int main()
{
	ifstream in("crystal.in",ios::in);
	ofstream out("crystal.out",ios::out);
	in>>n>>m;
	for(int i=0;i<n;i++)
	{
		in>>a[i];
	}
	a[n]=9223372036854775807;
	sort(a,a+1);
	dfsf(m,n-1);
	out<<ans;
	in.close();
	out.close();
	return 0;
}

