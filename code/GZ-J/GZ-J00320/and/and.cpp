//GZ-J00320     Îâº«·É 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i]&&a[j]>a[i]&&a[j+1])
			{
				sum=a[i]&&a[j];
			}
		} 
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
}

