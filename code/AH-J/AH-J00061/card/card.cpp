#include<bits/stdc++.h>
using namespace std;
int a[50000],n,m,t[50000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int s=1;
        for(int j=i;j<=n;j++){
            for(int k=s+1;k<j;k++){
                if(a[k]==a[j]) s=j;
            }
        }
        for(int o=s;o<=n;o++){
            if(t[a[o]]<n) t[a[o]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
