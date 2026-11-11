#include<bits/stdc++.h>
using namespace std;
struct node{
char c;
long long  k;
long long  mid=0;
};
node a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long  n,ans=0;
	cin>>n;
	long long num=0;
	for(long long  i=1;i<=n;i++)
	{
		cin>>a[i].k>>a[i].c;
		num+=a[i].k;
	}
	long long sum=num;
//	sum=(sum+1)/2;
	long long nw=1,pp=n;
	while(sum!=0)
	{
	//	if(a[now].c==a[pp].c)
		//
			long long q=min(a[nw].k,a[pp].k);
			if(a[nw].c!=a[pp].c) ans+=q;
			a[pp].k-=q;
			a[nw].k-=q;
			if(a[pp].k==0) pp--;
			if(a[nw].k==0) nw++;
			if(pp<=nw) break;
		//}
	}
	cout<<ans;
}
