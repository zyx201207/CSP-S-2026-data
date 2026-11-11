#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in" , "r" , stdin) ;
    freopen("travel.out" , "w" , stdout) ;
    string c1 , s1 , c2 , s2 ;
    cin >> c1 >> s1 >> c2 >> s2 ;
    bool a=0 , b=0 , c=0 , d=0 ;
    //1
    if (c1 == c2)
    {
        a = 1 ;
    }
    if (!a)
    {
        cout << "0000" ;
        return 0 ;
    }
    //2
    int s_1 = (s1[0] - '0') * 10 + (s1[1] - '0') ;
    int s_2 = (s2[0] - '0') * 10 + (s2[1] - '0') ;
    if (s_1 == s_2)
    {
        b = 1 ;
    }
    if (!b)
    {
        cout << 1000 ;
        return 0 ;
    }
    //3
    if ((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'A' && s2[2] == 'C'))
    {
        c = 1 ;
    }
    else if ((s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C'))
    {
        c = 1 ;
    }
    else if ((s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'C' && s2[2] == 'A'))
    {
        c = 1 ;
    }
    else if (s1[2] == 'D' && s2[2] == 'F')
    {
        c = 1 ;
    }
    else if (s1[2] == 'F' && s2[2] == 'D')
    {
        c = 1 ;
    }
    if (!c)
    {
        cout << 1100 ;
        return 0 ;
    }
    //4
    if ((s1[2] == 'A' && s2[2] == 'B') || (s2[2] == 'A' && s1[2] == 'B'))
    {
        d = 1 ;
    }
    else if ((s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B'))
    {
        d = 1 ;
    }
    else if ((s1[2] == 'D' && s2[2] == 'F') || s1[2] == 'F' && s2[2] == 'D')
    {
        d = 1 ;
    }
    if (!d)
    {
        cout << 1110 ;
        return 0 ;
    }
    //5
    if (a && b && c && d)
    {
        cout << 1111 ;
    }
    return 0;
}
