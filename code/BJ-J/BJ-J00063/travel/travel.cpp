#include<bits/stdc++.h>
using namespace std;
string f(int c1,int c2,int r,int x,char r1,char x1)
{
    if(c1==c2)
    {
        if(r==x)
        {
            if(!((r1=='C'&&x1=='D')||(r1=='D'&&x1=='C')))
            {
                if(abs(r1-x1)==1)
                    return "1111";
                else
                    return "1110";
            }
            else
                return "1100";
        }
        else
            return "1000";
    }
    else
        return "0000";
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int c3=(c1[0]-'0')*10+(c1[1]-'0');
    int c4=(c2[0]-'0')*10+(c2[1]-'0');
    int r,x;
    char r1=s1[2],x1=s2[2];
    if(r1=='F')r1=='E';
    if(x1=='F')x1=='E';
    r=(s1[0]-'0')*10+(s1[1]-'0');
    x=(s2[0]-'0')*10+(s2[1]-'0');
    cout<<f(c3,c4,r,x,r1,x1)<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
