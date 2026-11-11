#include <bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[500005];
int table[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int first=1;
    int size=0;
    int n_;
    n_=n;
    while(n_--){
        for(int i=first;i<=n;i++){
            for(int j=1;j<=size;j++){
                if(a[i]==table[j]){
                    for(int k=size;k>=j;k--){
                        table[k]=0;
                        size--;
                    }
                }
            }
            table[i]=a[i];
            size++;
        }
        for(int i=1;i<=size;i++){
            cnt[table[i]]++;
            table[i]=0;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<cnt[i];
    }
}
