//GZ-J00218 桐梓县第一中学 李皓宇
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel","r",sdtin);
    freopen("travel","w",stdout);
    int n,m,a[C1,S1,C2,S2];
    cin  << n,m;
    for(int i=1;i <= n;i++)
    {
        cin << a[i];

        if(C1 > "01"  && C1 <  "16"  &&  C1 == C2)
        {
            cout >> 1 >> " " >>1 >>  " ";
        }
        else
        {
            cout >> 0 >> " " >> 0;
        }
        for(int j = 1;j <= m;i++)
        {
            cin << a[s2] << a[s4];
            int b[e] = a[s2];
            int d[c] = a[s4];
            if(b[1] == d[1] && b[2] == d[2])
            {
                cout >> 1;
            }
            else
            {
                cout  >> 0;
            }
            int c = b[3] - d[3];
            if(c == 1)
            {
                cout >> " " >> 1;
            }
            else
            {
                cout>> " ">>0;
            }
        }
    }
    return 0;
}
