#include<bits/stdc++.h>
using namespace std;
string cc1,cc2,ss1,ss2;
char c1[3]={'A','B','C'},c2[2]={'D','F'};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> cc1 >> ss1 >> cc2 >> ss2;
    if(cc1!=cc2)
    {
        cout << "0000";
        return 0;
    }
    if(ss1[0]!=ss2[0]||ss1[1]!=ss2[1])
    {
        cout << "1000";
        return 0;
    }
    int cnt=0;
    for(int i=0;i<=1;i++)
    {
        if(ss1[2]==c2[i]) cnt++;
        if(ss2[2]==c2[i]) cnt++;
    }
    if(cnt==1)
    {
        cout << "1100";
        return 0;
    }
    if(cnt==2)
    {
        cout << "1111";
        return 0;
    }
    if(ss1[2]=='B'||ss2[2]=='B') cout << "1111";
    else cout << "1110";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
