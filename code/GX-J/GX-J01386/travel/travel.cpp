#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream ifs;
    ofstream ofs;
    ifs.open("travel.in");
    ofs.open("travel.out");
    bool no_same_c = true;
    bool no_same_p = true;
    bool no_same_h = true;
    int a,c;
    string b,d;
    ifs>>a>>b>>c>>d;
    if (a==c)
    {
        ofs<<1;
    }
    else
    {
        ofs<<0;
        no_same_c = false;
    }
    if ((b[0]+b[1]==d[0]+d[1])&&no_same_c)
    {
        ofs<<1;
    }
    else
    {
        ofs<<0;
        no_same_p = false;
    }
    if((((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||(b[2]=='C'||b[2]=='F')&&(d[2]=='C'||d[2]=='F'))&&no_same_p)
    {
        ofs<<1;
    }
    else
    {
        ofs<<0;
        no_same_h = false;
    }
    if(((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='F'&&d[2]=='D'))&&no_same_h)
    {
        ofs<<1;
    }
    else
    {
        ofs<<0;
    }
}
