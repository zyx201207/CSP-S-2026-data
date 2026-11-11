#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int t[N],a[N],l[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int len=0;
        for(int j=i;j<=n;j++){
            int cnt=len+1;
            for(int k=len;k>=1;k--){
                if(l[k]==a[j]){
                    cnt=k;
                }
            }
            len-=(len-cnt+1);
            l[++len]=a[j];
        }
        for(int j=1;j<=len;j++){
            t[l[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
