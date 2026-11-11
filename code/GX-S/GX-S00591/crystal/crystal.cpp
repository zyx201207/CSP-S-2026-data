#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    int su=0;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int l=i;l<n;l++){
            if(a[i]>a[l]){
                swap(a[i],a[l]);
            }
        }
    }
    int ca[n];
    for(int i=0;i<n-1;i++){
        ca[i]=a[i+1]-a[i];
    }

    for(int i=0;i<n;i++){
        int t,w;
        t=ca[i];
        w=2;
        for(int l=i+1;l<n-1;l++){
            t+=ca[l] * w;
            w++;
            if(t>m){
                break;
            }
            else if(w>su){
                su=w;
            }
        }
    }
    cout<<su;





    return 0;
}
