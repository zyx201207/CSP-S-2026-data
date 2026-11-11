#include <bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int m,n,p=10;
char c,d;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> a1 >> b >> b1;
    if(a==b)    cout << 1;
    else {
        cout << 0 << 0 << 0 << 0;
        return 0;
    }
    for(int i=0;i<2;i++){
        m+=(a1[i]-'0')*p;
        n+=(b1[i]-'0')*p;
        p=1;
    }
    if(m==n)    cout << 1;
    else {
        cout << 0 << 0 << 0;
        return 0;
    }
    c=a1[2];
    d=b1[2];
    if(c<='C' && d<='C')
        cout << 1;
    else if(c>='D'&& d>='D'){
        cout << 1 << 1;
        return 0;
    }
    else {
        cout << 0 << 0;
        return 0;
    }
    if(c-d==1 || d-c==1)
        cout << 1;
    else
        cout << 0;
    return 0;
}
