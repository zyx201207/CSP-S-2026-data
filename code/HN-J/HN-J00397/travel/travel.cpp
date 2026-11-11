#include<bits/stdc++.h>
using namespace std;
char t[4];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string t1,t2 ,t3,t4;
    cin>>t1>>t2>>t3>>t4;
    for(int i =2;i<=15;i++ )
    {
        for(int j ='A';j<='f';j++)
        {
            if(t[1]=t[3])
            {

                cout<<'1'<<"";
                continue;
            }
            else
            {

            }
            if(t[2]==j&&t[4]==j)
            {
                cout<<1<<"";
                continue;
            }
            else
            {
                cout<<'0'<<"";
                continue;
            }
            if(t[2]==i&&t[4]==i)
                {

                cout<<'1'<<"";
                continue;
                }
             else
             {

            cout<<'0'<<"";
            continue;
             }
             if(t[3]=='D'||t[3]=='C'&&t[4]=='D'||t[4]=='C')
             {
                 cout<<'1'<<"";
                 continue;
             }
            else
            {
                cout<<0<<"";
                continue;;
            }
    }
    return 0;
}
}
