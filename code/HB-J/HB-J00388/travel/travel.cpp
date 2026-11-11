#include<bits/stdc++.h>
using namespace std;
bool InAC(char c)
{
    return 'A'<=c&&c<='C';
}
bool InDF(char c)
{
    return c=='D'||c=='F';
}
bool OK(char C1,char C2)
{
    if(C1>C2) swap(C1,C2);
    if(C1=='A') return C2=='B';
    if(C1=='B') return C2=='C';
    if(C1=='D') return C2=='F';
    return 0;
}
void Solve()
{
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    if(c1!=c3) cout<<"0000\n";
    else
    {
        if(c2[0]==c4[0]&&c2[1]==c4[1])
        {
            if((InAC(c2[2])&&InAC(c4[2]))||(InDF(c2[2])&&InDF(c4[2])))
            {
                if(OK(c2[2],c4[2])) cout<<"1111\n";
                else cout<<"1110\n";
            }
            else cout<<"1100\n";
        }
        else cout<<"1000\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    Solve();
}
