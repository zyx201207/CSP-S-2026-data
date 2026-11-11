#include<bits/stdc++.h>
using namespace std;

int n,m,k1,k2;
string a,b;
char r1,r2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin >> n;
    cin >> a;
    cin >> m;
    cin >> b;
    for(char c:a)
    {
        if(c>='0' && c <= '9') k1=k1*10+(int(c)-'0');
        if(c>='A'&&c<='Z') r1=c;
    }
    for(char c:b)
    {
        if(c>='0' && c <= '9') k2=k2*10+(int(c)-'0');
        if(c>='A'&&c<='Z') r2=c;
    }

    if(n==m) cout << 1;
    else cout << 0;
    if(n==m&&k1==k2) cout << 1;
    else cout << 0;

    if(n==m&&k1==k2)
    {
        if(r1=='A'||r1=='B'||r1=='C')
        {
            if(r2=='A'||r2=='B'||r2=='C')
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        else
        {
            if(r2=='D'||2=='E') cout << 1;
            else cout << 0;
        }
    }
    else cout << 0;

    if(n==m&&k1==k2)
    {
        if(int(r1-r2==1) || int(r1-r2==-1))
        {
            if(r1=='C'&&r2=='D') cout << 0;
            else if(r2=='C'&&r1=='D') cout << 0;
            else cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    else cout << 0;

    return 0;
}
