#include<bits/stdc++.h>
using namespace std;
long long n,x,y,s,c;
struct stu{
	long long a;
	char c;
}a[200001],s1[200001],s2[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i].a>>a[i].c;
	if(n%2==0) x=n/2,y=n/2+1;
	else x=n/2,y=n/2+2;
	for(int i=1;i<=x;i++)
	s1[i].c=a[i].c,s1[i].a=a[i].a;
	for(int i=y;i<=n;i++)
	s2[++c].c=a[i].c,s2[c].a=a[i].a;
	for(int i=1;i<=x;i++)
	if(!(s1[x-i+1].c==s2[i].c))
	{
		if(n%2==0)
		{
			if(s1[x-i+1].a>=s2[i].a) s+=s2[i].a;
			else s+=s1[x-i+1].a;
		}
		else
		{
			if(s1[x-i+1].a>=s2[i].a) s+=s1[x-i+1].a;
			else s+=s2[i].a;
		}
	}
	cout<<s;
	return 0;
}
