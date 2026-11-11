#include <bits/stdc++.h>
using namespace std;
struct qq
{
long long n;
char a;
}s[200005];
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++)
cin>>s[i].n>>s[i].a;
int l=1,r=n;
long long sum=0;
while(l<r)
{
if(s[l].n==s[r].n)
{
if(s[l].a!=s[r].a)
sum+=s[l].n;

r--;
l++;
}
else
{
if(s[l].n>s[r].n)
{

if(s[l].a!=s[r].a)
{
sum+=s[r].n;
s[l].n-=s[r].n;
s[r].n=0;
}
else
s[l].n-=s[r].n;

r--;
}
else
{
if(s[l].a!=s[r].a)
{
sum+=s[l].n;
s[r].n-=s[l].n;
s[l].n=0;
}
else
s[r].n-=s[l].n;

l++;
}

}


}
cout<<sum;

   return 0;
}
