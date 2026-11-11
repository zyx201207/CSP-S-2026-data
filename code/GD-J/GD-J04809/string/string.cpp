#include<bits/stdc++.h>
using namespace std;
int a[200090]={};
char b[200090]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	int p=1,k=n;
	long long sum=0;
	while(p<k)
	{
		if(a[p]==a[k])
		{
			if(b[p]==b[k])
			{
				p++;
				k--;
			}
			else{
				sum=sum+a[p];
				p++;
				k--;
			}
		}
		else if(a[p]>a[k]){
			if(b[p]==b[k])
			{
				a[p]=a[p]-a[k];
				k--;
			}
			else{
				sum=sum+a[k];
				a[p]=a[p]-a[k];
				k--;
			}
		}
		else{
			if(b[p]==b[k])
			{
				a[k]=a[k]-a[p];
				p++;
			}
			else{
				sum=sum+a[p];
				a[k]=a[k]-a[p];
				p++;
			}
		}
	}
	cout<<sum;
	return 0; 
}
