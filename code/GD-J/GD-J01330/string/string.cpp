#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
char t;
struct pos{
	long long a;
	char b;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&s[i].a);
		scanf("%c",&t);
		if(t>='a'&&t<='z') s[i].b=t;
		else scanf("%c",&s[i].b);
	}
	for(int i=1,j=n;;)
	{
		if(i>=j) break;
		if(s[i].a==0) i++;
		if(s[j].a==0) j--;
		if(s[i].a==s[j].a)
		{
			if(s[i].b!=s[j].b) ans+=s[i].a;
			i++,j--;
		}
		else if(s[i].a>s[j].a)
		{
			if(s[i].b!=s[j].b) ans+=s[j].a;
			s[i].a-=s[j].a,j--;
		}
		else if(s[i].a<s[j].a)
		{
			if(s[i].b!=s[j].b) ans+=s[i].a;
			s[j].a-=s[i].a,i++;
		}
	}
	cout<<ans;
	return 0;
} 
