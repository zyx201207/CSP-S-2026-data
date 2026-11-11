#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],ans;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	string c,s1,s2;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int x=n,y=1;
	long long z=0,p=1;
	for(int i=0;i<n;i++)z+=a[i];
    for(int i=0;i<z;i++){
		for(int j=0;j<a[x];j++)s1[p]=c[x];
		p++;
		x--;
	}
	p=0;
	for(int i=0;i<z;i++){
		for(int j=0;j<a[y];j++)s2[p]=c[y];
		p++;
		y++;
	}
	for(int i=1;i<=z/2;i++)if(s1[i]!=s2[i])ans++;
    cout<<ans;
    return 0;
 }
