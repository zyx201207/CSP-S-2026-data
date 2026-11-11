#include<bits/stdc++.h>
using namespace std;
int a[100005];
int h[100005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,max=0,z,bian=0,q=0,p=0,zyyc;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        h[i]=a[i]-a[i-1];
    }
    /*for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }*/
    for(int i=1;i<=n;i++){
        for(int y=1;y<=n;y++){
            if(m-h[y]*y>0){
                bian++;
            }
            z=y;
        }
        if(max<bian){
            max=bian;
        }
        bian=0;
    }
    if(max==0){
        zyyc=0;
    }else if(max-z<0&&max!=0){
        zyyc=max-z;
        zyyc=zyyc*-1;
    }else if(max-z>0&&max!=0){
        zyyc=max-z;
    }
    //cout<<zyyc<<" "<<z;
    for(int w=1;w<=zyyc;w++){
            a[w]=a[max];
    }
    /*for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }*/
    for(int i=1;i<=n;i++){
        for(int y=1;y<=n;y++){
            if(a[i]==a[y]){
                q++;
            }
        }
        if(q>p){
            p=q;
        }
        q=0;
    }
    cout<<p;
    return 0;
}
