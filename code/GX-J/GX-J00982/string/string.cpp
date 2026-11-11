#include <bits/stdc++.h>
using namespace std;

long long n,s[100000],a,p,l,m;
char c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >>n;
    l+=n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        l+=a;
        for(int j=0;j<a;j++)
            s[j]=c;
    }

    for(int i=l-1;i>=p;i--){
        if(s[i]==s[p]) m++;
        p++;
    }
    cout <<m;
    return 0;
}
