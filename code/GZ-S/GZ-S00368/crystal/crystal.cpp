//GZ-S00368 北京师范大学贵阳附属中学 张朋
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int count=0;
    int a[100005]={};
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
   {
        count++;
        if(a[i+1]-a[i]>=m-i)
            break;

   }
    cout<<count;
return 0;
}
