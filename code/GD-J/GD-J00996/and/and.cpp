#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a[2005],b[2005][2005],sum1=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++){
				if(i!=j){
					sum1=max(sum1,a[i]&a[j]);
				}
			}
		}
	}
	cout<<sum1;
	return 0;
}
