#include<bits/stdc++.h>
using namespace std;
long long n,a,c,d;
char b;
string s;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++)
{cin>>a>>b;
for(int j=d;j<d+a;j++)
{s[j]=b;
}
d+=a;
}

for(long long i=0;i<d/2;i++)
if(s[i]!=s[d-1-i])c++;
cout<<c;	
	return 0;
}
