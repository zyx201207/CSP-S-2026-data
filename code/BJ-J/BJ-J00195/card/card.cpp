#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+10, M = 3e3+10;
int n, m, a[N],s[N],ans[N][M],b[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(a[j] == a[i]){
               s[i] = j;
               break;
            }
        }
    }
    for(int i = n;i>=1;i--){
        for(int j = i;j<=n;j++){
            if(s[j]>=i){
               for(int k = 1;k<=m;k++){
                   ans[i][k]+=ans[s[j]][k];
                   b[k]+=ans[s[j]][k];
               }
               break;
            }
            ans[i][a[j]]++;
            b[a[j]]++;
        }
        /*for(int i = 1;i<=m;i++) cout<<b[i]<<" ";
        cout<<endl;*/
    }
    
    for(int i = 1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
