#include<iostream>
using namespace std;
char str[100000006];
long long a,n,len,ans;
char c;
int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>> n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			str[len+j]=c;
		}
		len+=a;
	}
	int l=1,r=len;
	while(l<=r){
		if(str[l]!=str[r])
		{
			ans++;
		}
		l++;r--;
	}
	cout<<ans;
	return 0;
}
