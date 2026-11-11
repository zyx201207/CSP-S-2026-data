#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,sum,num;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n/2;i++)
	{
		if(b[i]!=b[n-i+1])
		{
			if(a[i]>a[n-i+1]){
				num+=a[n-i+1];
				if(b[i+1]==b[i])a[i+1]+=a[i]-a[n-i+1];
				else if(b[n-i]==b[i])a[n-1]+=a[i]-a[n-i+1];
				else {
					a[n-i]-=a[i]-a[n-i+1];
					num+=a[i]-a[n-i+1];
				}
			}
			else if(a[i]<a[n-i+1]) 
			{
				num+=a[i];
				if(b[i+1]==b[i])a[i+1]+=a[i]-a[n-i+1];
				else if(b[n-i]==b[i])a[n-1]+=a[i]-a[n-i+1];
				else {
					a[i+1]-=a[n-i+1]-a[i];
					num+=a[n-i+1]-a[i];
				}
			}
			else
			{
				num+=a[i];
			}
		}
		else
		{
			if(a[i]>a[n-i+1]){
				if(b[i+1]==b[i])a[i+1]+=a[i]-a[n-i+1];
				else if(b[n-i]==b[i])a[n-1]+=a[i]-a[n-i+1];
				else {
					a[n-i]-=a[i]-a[n-i+1];
					num+=a[i]-a[n-i+1];
				}
			}
			else if(a[i]<a[n-i+1]) 
			{
				if(b[i+1]==b[i])a[i+1]+=a[i]-a[n-i+1];
				else if(b[n-i]==b[i])a[n-1]+=a[i]-a[n-i+1];
				else {
					a[i+1]-=a[n-i+1]-a[i];
					num+=a[n-i+1]-a[i];
				}
			}
		}
	}
	cout<<num;
	return 0;
}
// 4 6 a 9 b 1 a 8 a
