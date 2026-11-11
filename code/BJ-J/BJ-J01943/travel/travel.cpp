#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string rd,r,xd,x;
    cin>>rd>>r>>xd>>x;
    if(xd!=rd)
    {
        cout<<"0000";
        return 0;
    }
    else
    {
        if(x[0]!=r[0]||x[1]!=r[1])
        {
            cout<<"1000";
            return 0;
        }
        else
        {
            if(x[2]>='D'&&r[2]<'D'||x[2]<'D'&&r[2]>='D')
            {
                cout<<"1100";
                return 0;
            }
            else
            {
                if(abs(r[2]-x[2])>1)
                {
                    cout<<"1110";
                    return 0;
                }
                else
                {
                    cout<<"1111";
                    return 0;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
}
