#include<bits/stdc++.h>
using namespace std;
int n,m,p=1,f,ans[500005];
int li[500005],a[500005];
int is(int s[],char x,int p){
    for(int i=0;i<=p;i++)
        if(s[i]==x)
            return i;
    return -1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
            cin>>li[i];
    for(int i=1;i<=n;i++){
        //memset(a,0,n+1);
        p=1;
        for(int j=i;j<=n;j++){
            f=is(a,li[j],p);
            if(f==-1)
                a[p++]=li[j];
            else
                p=f+1;
        }
        for(int j=1;j<p;j++)
            ans[a[j]]++;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    return 0;
}
