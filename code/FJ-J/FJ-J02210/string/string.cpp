#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],sum=0,ans=0;
char b;
string c="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b;
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			c+=b;
		}
	}
	for(int i=0;i<sum/2;i++){
		if(c[i]!=c[sum-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
