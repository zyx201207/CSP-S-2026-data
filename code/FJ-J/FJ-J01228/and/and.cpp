#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=i;j++)
		{
			if(a[i]&a[j]>maxn)
			{
				maxn=a[i]&a[j];
			}
		}
	}
	cout<<maxn<<endl;
	
	return 0;
}
