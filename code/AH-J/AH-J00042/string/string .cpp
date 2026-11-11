#include<bits/stdc++.h>
using namespace std;
int n,m,ans,f,b[200000005];
char c[200000005],a[200000005],d[200000005];
int main()
{
ios::sync_with_stdio(false);
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>b[i]>>c[i];
	d[i]=c[i];
	if(f==2)
	for(int j=1;j<=n;j++){
		if(d[j]!=c[i])
		{
			f=1; break;
		if(d[j]==c[i]) f=2;
	}
	m+=b[i];
     }
 }
if(f==2){
	cout<<0;
	return 0;
}
int l;
l=m/2;
int y=1,x=1;
while(y<=n){
	for(int i=1;i<=b[y];i++){
		a[x]=c[y];
		x++;
	}
	y++;
}
for(int i=1;i<=l;i++)
{
	if(a[i]!=a[m+1-i]){
		ans++;
	}
}
cout<<ans;
fclose(stdin);
fclose(stdout);
return 0;
}

