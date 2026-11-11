#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],pro[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = n;i>=1;i--){
        int cnt = 1;
        for(int j = i;j<=n;j++){
            pro[cnt] = a[j];
            int flag = 0;
            for(int k = 1;k<cnt;k++){
                if(pro[k] == -1){
                    continue;
                }
                if(flag){
                    pro[k] = -1;
                    continue;
                }
                if(pro[k] == a[j]){
                    pro[k] = -1;
                    flag = 1;
                }
            }
            cnt++;
        }
        int temp[m];
        for(int j = 1;j<=m;j++){
            temp[j] = 0;
        }
        for(int j = 1;j<cnt;j++){
            if(pro[j] != -1 && temp[pro[j]] != 1){
                temp[pro[j]] = 1;
                b[pro[j]]++;
            }
        }
    }
    for(int i = 1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}