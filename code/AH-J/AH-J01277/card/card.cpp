#include<bits/stdc++.h>
using namespace std;
int a[500005],t[500005],v[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        v[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        int h=i;
        while(h<=n){
            t[a[h]]++;
            if(h==v[a[h]]){
                h++;
            }else{
                h=v[a[h]]+1;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
