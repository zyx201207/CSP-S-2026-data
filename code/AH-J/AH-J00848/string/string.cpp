#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],num,sum;
string c[200005],s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)	{
		cin>>a[i]>>c[i];
		num+=a[i];
		for(int j=1;j<=a[i];j++) {
			s+=c[i];
		}
    }
    int len=s.size();
    num=num/2;
    for(int i=0;i<num;i++)
    {
		if(s[i]!=s[len-i-1]) sum++;
	}
	cout<<sum;
	return 0;
}


