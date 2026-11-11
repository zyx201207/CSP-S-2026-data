//GZ-S00368 北京师范大学贵阳附属中学 张朋
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int num=0;
    for(int i=0;i<m;i++)
    {
        int w;
        cin>>w;
        num+=w;
    }
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        int a,t;
        cin>>a>>t;
        num+=k-a+t;
    }
    cout<<num/4;
return 0;
}
