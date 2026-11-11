#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long a,b,e=0,f=0;
    char c[220000],d;
cin>>a;
for(int z=1;z<=a;z++){
    cin>>b>>d;
    for(int y=1;y<=b;y++){
        e++;
        c[e]=d;
    }
}
for(int z=1;z<=e/2;z++){
    if(c[z]!=c[e+1-z])f++;
}
cout<<f;
	return 0;
}
