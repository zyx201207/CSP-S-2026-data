#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct a{
    int num1;
    char c1;
};

a s[200000];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n = 0;
    static long long di = 0;

    cin >> n;

    int nu;
    for (nu = 0; nu < n; nu++){
        cin >> s[nu].num1;
        cin >> s[nu].c1;
    }

    int an, bn;
    char ac, bc;
    an = s[0].num1;
    bn = s[nu - 1].num1;
    ac = s[0].c1;
    bc = s[nu - 1].c1;
    for (int i = 0,j = nu - 1; i < j;){
        if (ac != bc)
            di += min(an, bn);
        if (an > bn){
            j--;
            an = an - bn;
            bn = s[j].num1;
            bc = s[j].c1;
        }
        else if(an == bn){
            j--;
            i++;
            an = s[i].num1;
            ac = s[i].c1;
            bn = s[j].num1;
            bc = s[j].c1;
        }
        else{
            i++;
            bn = bn - an;
            an = s[i].num1;
            ac = s[i].c1;
        }
    }

    cout << di;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

