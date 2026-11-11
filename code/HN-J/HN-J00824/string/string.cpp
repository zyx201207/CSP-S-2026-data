#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string a;
    int b,c,x=0;
    char d;
    for(int i=1;i<=b;i++){
            cin >> c;
            cin >> d;
        for (int j=x;j<x+c;j++){
            a[x] = d;
        }
        x += c;
    }
    string fan = a;
    for (int g=0;g<x+c;g++){
        a[g] = fan[x+c-1];
    }
    int h=0;
    for(int l=0;l<x+c;l++)
    {
        if (a[l] != fan[l])
        {
            h++;
        }
    }
    cout << h/2;
    return 0;
}

