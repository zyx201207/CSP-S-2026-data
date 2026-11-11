#include<bits/stdc++.h>
using namespace std;
string rr1,xx1,rr2,xx2,s="";
int  main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin>>rr1>>xx1>>rr2>>xx2;
    int r=(xx1[0]+xx1[1])-'0',w=(xx2[0]+xx2[1])-'0';

    if(rr1==rr2)
    {
        s+='1';
        if(r==w){
            s+='1';
            if((xx1[2]=='F'&&xx2[2]=='D')||(xx1[2]=='D'&&xx2[2]=='F')||(xx1[2]=='C'&&xx2[2]=='B')||(xx1[2]=='B'&&xx2[2]=='C')||(xx1[2]=='B'&&xx2[2]=='A')||(xx1[2]=='A'&&xx2[2]=='B')||(xx1[2]=='C'&&xx2[2]=='A')||(xx1[2]=='A'&&xx2[2]=='C')   )
            {
                s+='1';
                if(    (xx1[2]=='F'&&xx2[2]=='D')||(xx1[2]=='D'&&xx2[2]=='F')||(xx1[2]=='C'&&xx2[2]=='B')||(xx1[2]=='B'&&xx2[2]=='C')||(xx1[2]=='B'&&xx2[2]=='A')||(xx1[2]=='A'&&xx2[2]=='B'))
                    s+='1';
                else s+='0';

            }
            else s+="00";
        }
        else s+="000";
    }
    else s+="0000";
    cout<<s;
    return 0;
}