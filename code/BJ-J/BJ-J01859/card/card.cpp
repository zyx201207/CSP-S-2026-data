#include<bits/stdc++.h>
using namespace std;

int a[500005];
int t[500005];
int l[500005];
int cnt[200005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++){

        int top=0,l=0;
        memset(t,0,sizeof(t));

        for(int j=i;j<=n;j++){
            bool f=0;
            t[top++]=a[j];
            for(int k=top-2;k>=0;k--){
                if(t[k]==a[j]){
                    f=1;
                    l=k;
                    break;
                }
            }
            if(f==1){
                for(int k=l+1;k<top;k++) a[k]=0;
            }
            top=l+1;
        }


        for(int j=0;j<top;j++){
            cnt[t[j]]++;
        }
    }

    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    cout<<endl;
    return 0;
}
