#include<bits/stdc++.h>
using namespace std;
int n,a[200007],v[200007];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            v[a[j]]++;
            bool flag=1;
            for(int k=i;k<j;k++){
                if(a[k]==a[j]){
                    flag=0;
                }
            }
            if(!flag){
                for(int k=i;k<j;k++){
                    v[a[k]]--;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<v[i]<<' '
    }
    return 0;
}
