//GZ-S00230  遵义市第五中学 秦钰晗 
#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int cnt=0,t=0,h=0,sum=0;
	for(int j=0;j<n;j++)
	{
		if(a[j]>=a[j+1])
		{
		t=a[j];
		}
		cnt=cnt+(t-a[j]);
		if(cnt!=m)
		{
			
		}
	}
	cout<<cnt;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

