#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005],b[300005],c[500005];
bool f=0;

int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int x=n;
    while(x--){
        for(int i=n-x;i<=n;i++){
            b[a[i]]++;
            if(b[a[i]]>1){
                f=0;
                for(int j=n-x;j<=i;j++){
                    if(f=1) b[a[j]]--;
                    if(a[j]==a[i]){
                        f=1;
                        continue;
                    }
                }
            }
        }
        for(int i=1;i<=m;i++){
            c[i]+=b[i];
            b[i]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }

    return 0;
}
