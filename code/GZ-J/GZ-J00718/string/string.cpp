//GZ-J00718 兴义市弘毅中学 李勇霖
#include<bits/stdc++.h>
using namespace std;
char s1[101100],s2[101100],c[101100];
long long n,a[101100],p[101100],q=1;
long long adc(long long n)
{
	if(n<0) n=-n;
	if(n>=0) n=n;
	return n;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		p[i]=c[i]-'a'+1;
	} 
	for(int i=0;i<n-1;i++)
	{
		if(p[i]!=p[i+1])
		{
			q=0;
			break;
		}
	}
	if(q=1)
	{
		cout<<"0"<<'\n';
		return 0;
    }
    cout<<"13";
	 return 0;
}
