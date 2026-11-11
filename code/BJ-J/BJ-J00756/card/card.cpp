#include <bits/stdc++.h>
using namespace std;
long long a[10005],b[10005],v[10005],l[10005];
bool c[10005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=10000;i++)
        c[i]=true;
    int j=0;
    while(n-j<=0){
        for(int i=1+j;i<=n;i++){
            if(c[i]){
                b[i]=a[i];
                c[i]=false;
                v[a[i]]=i;
            }
            else{
                for(int k=v[a[i]]+1;k<=i;k++){
                    b[k]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(b[i]=j+1){
                l[i]++;
            }
        }
        j++;
    }
    for(int i=1;i<=n;i++){
        if(l[i]!=0){
            cout<<l[i]<<" ";
        }
    }
    return 0;
}
