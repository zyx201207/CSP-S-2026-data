#include<bits/stdc++.h>
using namespace std;
long long n,m,a,t[300005],q[300005];
string s2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a);s2+=(a+'0');
	}
	for(int i=1;i<=n;i++)
	{
		string s="",s3="";s3+=s2;
		for(int j=0;j<s3.size();j++)
		{
			s+=s3[j];
			int l=s.size();
			if(t[s[l]-'0']==-1) t[s[l]-'0']=l;
			if(t[s[l]-'0']!=-1)
			{
				s=s.erase(t[s[l]-'0'],l-1-t[s[l]-'0']);
				l=s.size();
				t[s[l]-'0']=l;
			}
		}
		for(int j=1;j<=m;j++) t[j]=-1;
		for(int j=1;j<s.size();j++) q[s[j]-'0']++;
		s2=s2.substr(1,n-i);
	}
	for(int i=1;i<=m;i++)
	{
		printf("%lld ",q[i]);
	}
	return 0;
} 
