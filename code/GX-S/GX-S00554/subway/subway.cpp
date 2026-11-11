#include<bits/std.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int a,b,c,s,f,sum=0;
    cin>>a>>b>>c>>s>>f;
    int n[10089];
    for(int i = 1;i<=c;i++)
    {
        cin>>n[i];
    }
    int t,m,t1[40203],t2[99333];
    cin>>t;
    for(int i = 1;i<=t*2;i++)
    {
        cin>>t1[i];
    }
    cin>>m;
    for(int i = 1;i<=m*2;i++)
    {
        cin>>t2[i];
    }
    int,f1[3],f2[3];
    for(int i= 1;i<=f;i++)
    {

        cin>>f1[i];

    }
    for(int i = 1;i<=f;i++)
    {

        cin>>f2[i];
    }
    if(t1[3]==f[2]||t1[5]==f[2])
    {
        sum+=n[1]+t1[2]+t1[4]+n[2];
    }
    cout<<sum;
    return 0;
}
