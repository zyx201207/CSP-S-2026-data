//GZ-S00368 北京师范大学贵阳附属中学 张朋
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++)
    {
        int n,d;
        cin>>n>>d;
        for(int j=0;j<n;j++)
       {
            int a;
            cin>>a;
       }
        if(n/d>1&&n/d<3)
        {
            if(n%d!=0)
                cout<<n/d<<endl;
            else
                cout<<n/d-1<<endl;
        }
        else
            cout<<'0'<<endl;
    }
return 0;
}
