#include<bits/stdc++.h>
using namespace std;
int n,m;
bool b[200005][35];
int a[200005];
int ans;
struct Choose{
	int last,nxt;
}l[200005];
void pop(Choose x)
{
	l[x.last].nxt=x.nxt;
	l[x.nxt].last=x.last;
}
void Special()
{
	int res=a[l[0].nxt];
	int q=l[0].nxt;
	for(; q!=-1; q=l[q].nxt)
	{
		res=res&a[q];
	}
	cout<<res;
	exit(0);
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	l[0].nxt=1;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		for(int j=0; j<=30; j++)
		{
			b[i][j]=(a[i]&(1<<j));
		}
		l[i].last=i-1,l[i].nxt=i+1;
	}
	/*
	for(int i=1; i<=n; i++)
	{
		for(int j=30; j>=0; j--)
		{
			cout<<(b[i][j]?1:0);
		}
		cout<<"\n";
	}
	*/
	l[n].nxt=-1;
	int q,sum;
	for(int s=30; s>=0; s--)
	{
		q=l[0].nxt,sum=0;
		for(; q!=-1; q=l[q].nxt)
		{
			if(b[q][s]) sum++;
		}
		if(sum<m) continue;
		q=l[0].nxt;
		for(; q!=-1; q=l[q].nxt)
		{
			if(!b[q][s]) pop(l[q]);
		}
		ans+=(1<<s);
		if(sum==m) Special();
	}
	cout<<ans;
	
	return 0;
} 
/*
从高到低依次比较所有二进制位
若本位二进制为 1 的大于等于 m，则 ans += 本位代表的十进制数值，并限制后面二进制位数据的选取范围
否则直接进入下一位
可证明，当前位一定比后面所有的更好。

应该不能被 TLE qwq 
5 3
31 3 1 15 7
*/
