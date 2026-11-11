#include <bits/stdc++.h>
using namespace std;

void otpfnc(bool b)
{
    if(b==true) cout << 1;
    else cout << 0;
    return;
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;

    bool q1=false,q2=false,q3=false,q4=false;
    if(c1==c2) q1=true;
    if(q1==true&&(s1[0]==s2[0]&&s1[1]==s2[1])) q2=true;
    if(q1==true&&q2==true&&(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F')))) q3=true;
    if(q1==true&&q2==true&&q3==true)
    {
        char c1=min(s1[2],s2[2]),c2=max(s1[2],s2[2]);
        if(c1=='D'&&c2=='F') q4=true;
        else if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))&&(c2-c1==1)) q4=true;
    }
    otpfnc(q1);
    otpfnc(q2);
    otpfnc(q3);
    otpfnc(q4);

    return 0;
}
