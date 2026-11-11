#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[N]={},s[N]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int c[N]={};
        int cnt = 0;
        for(int j=i;j<=n;j++){
            cnt++;
            c[cnt] = a[j];
            for(int k=1;k<cnt;k++){
                if(c[k]==c[cnt]){
                    for(int l=k+1;l<=cnt;l++){
                        c[l] = 0;
                    }
                }
            }
        }
        for(int j=1;j<=cnt;j++){
            s[c[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}
