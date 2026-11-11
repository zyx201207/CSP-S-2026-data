#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int a[2000005],b[2000005];
int x[4000005];
int in=1;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d",&n,&k);
        int mi=INT_MAX;
        for(int i=1;i<=n-1;i++){
            scanf("%d%d",&a[i],&b[i]);
            x[in]=a[i];
            in++;
            x[in]=b[i];
            in++;
        }
    }
    sort(x+1,x+in+1);
    int f=0;
    for(int i=2;i<=in;i++){
        if(x[i]!=x[i+1]){
            cout<<x[i]<<endl;
            f++;
        }
        if(f==t){
            return 0;
        }
    }

    return 0;
}
