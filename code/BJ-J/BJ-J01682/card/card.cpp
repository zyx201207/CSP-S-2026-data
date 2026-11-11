#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],top,ans[300005];
struct card{
    bool f=false;
    long long x=0;
}c[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        top=0;
        for(int j=1;j<=m;j++){
            c[j].f=false;
            c[j].x=0;
        }
        for(int j=i;j<=n;j++){
            if(c[a[j]].f==0){
                b[++top]=a[j];
                c[a[j]].f=true;
                c[a[j]].x=top;
            }else{
                int y=c[a[j]].x;
                for(int g=y+1;g<=top;g++){
                    c[b[g]].f=false;
                    c[b[g]].x=0;
                }
                top=y;
            }
        }
        for(int i=1;i<=top;i++){
            ans[b[i]]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
