#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2, s[]={" ", "A", "B", "C", "D", "E"};
bool f1, f2, f3, f4;
int main()
{
    freopen("string.in", "w", "in");
    freopen("string.out", "r", "out");
    cin >> c1 >> s1 >> c2 >> s2;
    s1=' '+s1;
    s2=' '+s2;
    if (c1==c2) f1=true;
    if (f1 && s1[1]==s2[1] && s1[2]==s2[2]) f2=true;
    if (f2)
    {
        if ((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s[3]=='C')) f3=true;
        if ((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='D'||s2[3]=='F')) f3=true;
    }
    if (f3) for (int i=1; i<=3; i++) if (s[i]==s1[3]&&s[i+1]==s2[3]||s[i-1]==s2[3]) f4=true;
    cout << f1 << f2 << f3 << f4;
}
