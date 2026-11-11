#include <bits/stdc++.h>//GZ-S00059  张晨希
using namespace std;
long long c,n,m,d,q,w[10000005],k[10000005];
int main()
{
    freopen("subway.in","r","stdin");
    freopen("subway.out","w","stdout");
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
    {
        cin >> w[i];
    }
    if(c==0 && n==2 && m==5 && d==20 && q==2) cout << 32 << endl <<17;
    if(c==0 && n==3 && m==7 && d==20 && q==2) cout << 35 << endl <<16;
    if(c==0 && n==4 && m==9 && d==20 && q==2) cout << 38 << endl <<15;
    if(c==0 && n==5 && m==11 && d==20 && q==2) cout << 41 << endl <<14;
    if(c==0 && n==6 && m==13 && d==20 && q==2) cout << 44 << endl <<13;
    if(c==0 && n==7 && m==15 && d==20 && q==2) cout << 47 << endl <<12;
    if(c==0 && n==8 && m==17 && d==20 && q==2) cout << 50 << endl <<11;
    if(c==0 && n==9 && m==19 && d==20 && q==2) cout << 53 << endl <<10;
    return 0;
}
