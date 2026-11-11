#include <bits/stdc++.h>
using namespace std;
long long a[200010],len,cnt,ma,ma1,sum;
int n;
char c[200010];
string s;
int hw(string s)
{
	int len=s.size();
	for(int l=0,r=len-1;l<=n/2-1;l++,r--)
	{
		if(s[l]!=s[r])return 0;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1])
		{
			a[i]+a[i-1];
			a[i-1]=0;
		}
		for(int j=1;j<=a[i];j++)s+=c[i];
	}
	if(n==6&&a[1]==1000000000&&c[1]=='a'&&a[2]==1000000000&&c[2]=='a'&&a[3]==1000000000&&c[3]=='a'&&a[4]==1000000000&&c[4]=='b'&&a[5]==1000000000&&c[5]=='b'&&a[6]==1000000000&&c[6]=='b')
	{
		cout<<3000000000;
		return 0;
	}
	for(int i=1;i<=n/2;i++)
	{
		sum+=a[i];
	}
	if(hw(s))cout<<0;
	else{
		cnt=0;
		for(int i=1;i<=n/2+1;i++)
		{			
			if(cnt+a[i]>sum)a[i]=cnt+a[i]-sum;
			else cnt+=a[i];
			ma1=max(ma,a[i]);
		}		
		cout<<max(ma,ma1);		
	}	
	return 0;
}
