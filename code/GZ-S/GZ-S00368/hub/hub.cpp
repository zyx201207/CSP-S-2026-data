//GZ-S00368 北京师范大学贵阳附属中学 张朋
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int u[10005]={};
    int v[10005]={};
    int num=0;
    for(int i=0;i<t;i++)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>u[i]>>v[i];
            if(u[i]==v[i+1]||u[i]==u[i+1]||v[i]==v[i+1])
                num++;
        }
    }
    cout<<num/3;
return 0;
}
