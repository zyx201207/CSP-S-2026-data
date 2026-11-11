#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],b[1000000],c[1000000],s,t;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++){
        for(int i = 1;i <= n;i++){
            b[i] = 0;
        }
        s = 0;
        for(int j = i;j <= n;j++){
            bool f = true;
            for(int z = 1;z <= s;z++){
                if(b[z]==a[j]){
                    f = false;
                    t = z;
                    break;
                }
            }
            if(f){
                b[s+1] = a[j];
                s++;
            }else{
                s = t;
            }
        }
        for(int i = 1;i <= s;i++){
            c[b[i]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}