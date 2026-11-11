//GZ-J00590 北京师范大学贵阳附属中学 张朋
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int c[200005]={};
    for(int i=0;i<n;i++)
        cin>>c[i];
    sort(c,c+n);
    for(int i=0;i<n;i++)
        cout<<c[i]<<" ";
    cout<<endl;
    int num=c[n-m];
    for(int i=1;i<m;i++)
    {
        num=(c[n-m+i] & num);
    }
    cout<<num;
return 0;
}
