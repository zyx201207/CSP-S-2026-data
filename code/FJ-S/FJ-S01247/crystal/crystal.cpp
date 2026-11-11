#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in""r"stdin)
	freopen("crystal.out""w"stdout)
int n,m;
int sycn_with_stdic(false);
cin.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
	for(int j=1;j<=m;j++)
	{
		int sum;
		int a=[100005];
		if(a[i]=a[j]){
			a[i][j]=a[i-1][j-1]+1;
			sum++;
		}else
		{
			a[i][j]=max(a[i-1][j].a[i][j-1]);
		}
	}
}
	return 0;
}
