#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m[500005],p,o[300000],w[300000],a=1;
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>m[n];
    }
    while(a<=n){
        for(int j=a;j<=n;j++){
            o[m[j]]+=1;
            if(o[m[j]]==2){
                int o[300000];
            }
        }
        for(int i=1;i<=n;i++){
            w[i]+=o[i];
        }
        int o[300000];
        for(int i=1;i<=p;i++){
        cout<<w[i]<<" ";
    }
        a++;
    }
    for(int i=1;i<=p;i++){
        cout<<w[i]<<" ";
    }

    return 0;
}
