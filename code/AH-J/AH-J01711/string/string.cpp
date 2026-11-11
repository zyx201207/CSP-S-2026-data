#include<bits/stdc++.h>
using namespace std;
const long long N=1000000005;
char s[N];
int n;
long long ans,sum;
int main()
{
	
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    while(n--)
    {
		long long x;
		char y;
		cin>>x>>y;
		ans+=x;
		for(long long i=ans-x+1;i<=ans;i++) s[i]=y;
	}
	for(long long i=1;i<=ans/2;i++) if(s[i]!=s[ans-i+1]) sum++;
	cout<<sum<<endl;
    return 0;
}
