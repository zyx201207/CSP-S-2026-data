#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int last[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int i  =1;i <= n;i++){
        int h[500005] = {};
        int s = i-1;
        for(int j = i;j <= n;j++){
            int flag = 1;
            s++;
            for(int k  = i;k < j;k++){
                if(a[j] = h[k]){
                    flag = 0;
                }
            }
        if(flag){
            h[s] = a[j];
        }
        else{
            for(int k = i;k <= j;k++){
             h[i] =0;
            }
            s = i;
            h[s] = a[j];
        }
        }
        for(int j = i;j <= n;j++){
            last[h[j]] ++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout<<last[i]<<' ';
    }




    return 0;}
