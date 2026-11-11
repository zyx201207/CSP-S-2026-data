#include<bits/stdc++.h>
using namespace std;
long long int s[100000001],a[100000001]; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i]>>a[i];
	}
	if(n==1)
	{
		cout<<0;
	}
	else if(a[0]==a[1])
	{
		if(s[0]<s[1])
		{
			cout<<s[0];
		}
		else
		{
			cout<<s[1];
		}
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 
