#include<bits/stdc++.h>
using namespace std;
char a[100000001],b[100000001],c;
int n,x,h,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>c;
		for(int i=1;i<=x;i++) a[++h]=c,b[h]=c;
	}
	reverse(b+1,b+h+1);
	for(int i=1;i<=h/2;i++) if(a[i]!=b[i]) s++;
	cout<<s<<'\n';
	return 0;
}

