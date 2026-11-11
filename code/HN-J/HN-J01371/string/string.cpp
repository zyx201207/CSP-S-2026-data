#include<bits/stdc++.h>
#define int long long
using namespace std;
unsigned long long n,a,cnt=0,sum=0,ans=0;
char c;
string s=" ";
signed main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a>>c;
    	sum+=a;
    	for(int j=1;j<=a;j++)
    	    s+=c;
	}
	double mid;
	if(sum%2==0)
	    mid=(double)((sum+1)/2);
	else
	    mid=(int)(sum/2+1);
	for(int i=1,j=sum;i<mid,j>mid;++i,--j)
		if(s[i]!=s[j])
			ans++,s[i]=s[j];
	cout<<ans;
	return 0;
}
