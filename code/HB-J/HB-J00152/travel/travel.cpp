#include <bits/stdc++.h>

using namespace std;
char a[11];
int x=0,y=0;int q=0,w=0,e=0,r=0;int t=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=10;i++)
    {
        cin>>a[i];
    }
    if(a[1]==a[6]&&a[2]==a[7])
    {
        q=1;
        if(a[4]==a[9]&&a[3]==a[8])
        {
            w=1;
            if (a[5]=='D'||a[5]=='F')
            {
                x=2;
            }else
            {
                x=1;
            }
            if (a[10]=='D'||a[10]=='F')
            {
                y=2;
            }else
            {
                y=1;
            }
            if(x==y)
            {
                e=1;
                if(a[3]==a[8]&&a[4]==a[9])
                {
                    if((a[5]=='D'&&a[10]=='F')||(a[10]=='F'&&a[5]=='D'))
                    {
                        r=1;
                    }else if((a[5]=='A'&&a[10]=='C')||(a[10]=='A'&&a[5]=='C'))
                    {

                    }else
                    {
                        r=1;
                    }
                }
            }

        }
    }
    cout<<q<<w<<e<<r;
    return 0;
}
