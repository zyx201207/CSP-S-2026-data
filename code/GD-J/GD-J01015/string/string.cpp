#include<bits/stdc++.h>
using namespace std;
long long n,x,a[100005],h,ans;
char c[100005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		h+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			s[x]=c[i];
			x++;
		}
	}
	x--;
	for(int i=1;i<=h/2;i++)
	{
		if(s[i-1]!=s[h-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}//RP++!
