//GZ-J00281 qiuyirong
#include<bits/stdc++.h>
using  namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a,b,c,d;
    if(n==1)
    {
        cin>>a,b;
        cout<<"0";
    }
    if(n==2)
    {
        cin>>c>>d;
        if(b==d)
        {
            cout<<"0";
        }
         else
        {
            cout<<"1";
        }
    }
    return 0;
}
