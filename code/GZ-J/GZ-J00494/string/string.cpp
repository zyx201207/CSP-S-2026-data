//GZ-J00494 贺举柱 遵义航天中学
#include <bits/stdc++.h>
using namespace std;
struct s{
	int num;
	char x;
};
s a[1000000];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	long long cs=0,sum=0;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i].num>>a[i].x;
		sum+=a[i].num;
	}
	bool st=false;
	for(int i=1;i<n;i++)
	{
		if(a[i-1].x!=a[i].x)
		{
			st=true;
		}
	}
	if(st==false)
	{
		cout<<cs;
	}
	return 0;
}

