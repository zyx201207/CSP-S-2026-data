#include<bits/stdc++.h>
using namespace std;
string a,b[2005];
long long c,d,e=1,f=0,ans=0;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin >> c;
for(long i=1;i<=c;i++){
    cin >> d >> a;
    for(long long i=1;i<=d;i++)
    {b[e] = a;
    e++;
    }
}
for(long long i=1;i<=e/2;i++){
    if(b[f]!=b[e-f])ans++;
    f++;
}
cout <<ans;
return 0;
}
