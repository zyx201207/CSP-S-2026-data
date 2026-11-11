#include<bits/stdc++.h>
using namespace std;
int n,m,ma,a[200005],sum,nd=1;
bool b[200005]={true};
void zsrpyh(int k)
{
    if(k==0){
        if(nd>ma)ma=nd;
        return;
    }
    for(int e=0;e<n;e++){
        if(k==m)nd=a[e];
        else if(b[e])nd=nd&a[e],b[e]=false;
        zsrpyh(k-1);
        b[e]=true;
    }
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    zsrpyh(m);
    cout<<ma;
    return 0;
}
