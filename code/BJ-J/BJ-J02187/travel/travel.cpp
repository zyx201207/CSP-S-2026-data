#include<string>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a[4];
    int cnt=0;
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    if(a[0][0]==a[2][0]&&a[0][1]==a[2][1])
    {
        cout<<1;
        cnt++;
        if(a[1][0]==a[3][0]&&a[1][1]==a[3][1])
        {
            cout<<1;
            cnt++;
            if(a[1][2]<='C'&&a[3][2]<='C'||a[1][2]>'C'&&a[3][2]>'C')
            {
                cout<<1;
                cnt++;
                if(a[1][2]-a[3][2]<=1&&a[3][2]-a[1][2]<=1)
                {
                    cout<<1;
                    cnt++;
                }
            }
        }
    }
    for(int i=cnt;i<4;i++)
        cout<<0;
    return 0;
}