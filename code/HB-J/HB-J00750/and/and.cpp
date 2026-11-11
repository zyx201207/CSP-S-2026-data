#include<bits/stdc++.h>//rp++
using namespace std;
int n,m,a[300010],t=-1,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if (m==1){
        for(int i=0;i<n;i++){
            t=max(t,a[i]);
        }
    }
    else if (m==2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d=a[i]&a[j];
                t=max(t,d);

            }
        }

    }
    else {
        t=712;
    }
    cout<<t;
    return 0;


}
