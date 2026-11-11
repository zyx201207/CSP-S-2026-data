#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n m;
    int a[500001];
    int b[500001];
    int ans[300001];
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        b[i] = a[i];
    }
    for(int i = 0;i<n;i++){
        for(int j = i;j<n-1;j++){
            for(int k = j;k<n;k++){
                if(b[j]==0)break;
                if(b[j]==b[k]){
                    for(int l = j;l<k;l++){
                        b[l] = 0;
                    }
                }
            }
        }
        for(int j = i;j<n;j++){
            ans[b[j]]++;
            b[j] = a[j];
        }
    }
    for(int i = 1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
