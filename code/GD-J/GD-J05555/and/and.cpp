#include <bits/stdc++.h>
using namespace std;

int mdd(int x,int y){
	return x&y;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int q[100005];
	for(int i=1;i<=n;i++)
	{
		cin>>q[i];
	}
	if(m==1){
		sort(q+1,q+n+1);
		cout<<q[n];
		return 0;
	}
	else if(m==n)
	{
		int cnt=q[1];
		for(int i=1;i<=n;i++){
			cnt=mdd(cnt,q[i]);
		}
		cout<<cnt;
		return 0;
	}
	else if(m==2)
	{
		int mxa=0;
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				mxa=max(mxa,mdd(q[i],q[j]));
			}
		}
		cout<<mxa;
		return 0;
	}
	else if(m==n-1){
		int cnt=q[1];
		int cst=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
			{
				if(j!=cst){
					cnt=mdd(cnt,q[j]);
				}
			}
			cst++;
		}
		cout<<cnt;
		return 0;
	}
	
	return 0;
}
