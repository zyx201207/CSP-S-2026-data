#include<iostream>
#include<string>
using namespace std;
const int N=2e9+10;
int n;
long long cnt=0;
int h[N]={0}; 
string s[N];
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		h[int(c)]+=a;
		for(int i=cnt;i<cnt+a;i++) s[i]=c;
		cnt+=a;
		
	}
	
	for(int i=0;i<cnt/2+1;i++) 
	{
		

		if(s[i]!=s[cnt-i-1])
		{
			s[i]=s[cnt-i-1];
			ans++;
		}
		
	}
	cout<<ans<<endl;
	return 0;
 } 
