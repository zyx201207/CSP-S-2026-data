#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int a[100001], j[100001], k[10000], card[1000001];
    cin>>n>>m;
        int b = 1;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        k[i] = 0;
        j[i] = a[i];
    }
    while(b <= n){
        for(int i = 1; i <= n; i++){
            k[i] = 0;
            a[i] = j[i];
        }
        for(int i = b; i <= n;i ++){
            if(a[i] == a[i + 1]){
                a[i] = 0;
            }
            else card[a[i]]++;
        }
        b++;
        }

    for(int i = 1; i <= m; i++){
        cout<<card[i]<<" ";
    }
    return 0;
}
