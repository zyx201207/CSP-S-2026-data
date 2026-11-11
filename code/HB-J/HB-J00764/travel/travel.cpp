#include<bits/stdc++.h>
using namespace std;
const int N=1005;
string rc,rz,xc,xz;
bool a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> rc >> rz >> xc >> xz;
    a=false;
    b=false;
    c=false;
    d=false;
    if(rc==xc)//在同一节车厢
    {
        a=true;
        if(rz[0]==xz[0] && rz[1]==xz[1])//在同一节车厢的同一排
        {
            b=true;
            char t1,t2;
            t1=rz[2];
            t2=xz[2];
            //且位于过道的同一侧
            if((t1=='A' && (t2=='B' || t2=='C')) ||  (t1=='B' &&(t2=='A' || t2=='C')) || (t1=='C' &&(t2=='B' || t2=='C')))
                c=true;
            if((t2=='A' && (t1=='B' || t1=='C')) ||  (t2=='B' &&(t1=='A' || t1=='C')) || (t2=='C' &&(t1=='B' || t1=='C')))
                c=true;
            if((t1=='D' && t2=='F') || (t1=='F' && t2=='D'))
                c=true;
            
            //座位是否相邻
            if((t1=='A' && t2=='B') ||  (t1=='B' && t2=='C') || (t1=='D'&& t2=='F'))
                d=true;
            else if((t2=='A' && t1=='B') ||  (t2=='B' && t1=='C') || (t2=='D'&& t1=='F'))
                d=true;
        }
    }
    cout << a << b << c << d;
    return 0;
}
