#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,v;
    cin>>n>>m;
    int a[n+1],b[m+1]c[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        b[i]=0;
    for(int i=1;i<=n;i++){
        int s=i+1;
        for(int l=1;l<=n;l++)
            c[i]=0;
        for(int j=i+1;j<=n;j++){
            s+=1;
            for(int t=i;t<s;t++){
                if(a[s]==a[t]){
                    for(int u=t+1;u<=s;u++)
                        c[u]=0;
                    s=t;
                    break;
                }
                else
                if(t==s-1)
                    c[s]=a[j];
            }
        }
        for(int j=i;j<=s;j++){
            if(c[j]!=0)
                b[c[j]]+=1;
        }
    }
    for(int i=1;i<=m;i++)
        cout<<b[i]<<" ";
    return 0;
}
