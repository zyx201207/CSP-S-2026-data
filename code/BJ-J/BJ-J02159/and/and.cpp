#include<bits/stdc++.h>
using namespace std;
int n,m,ma,mb,mc;
int a[200005];
int main(){
    freopen("and.in","w",stdin);
    freopen("and.out","r",stdout);
    cin>>n>>m;
    mb=a[0];
    cin>>a[1];
    ma=max(ma,a[1]);
    for(int i=1;i<n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
        mb&=a[i];
    }
    if(m==2){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mc=max(mc,a[i]&a[j]);
            }
        }
        cout<<mc;
    }
    else if(m==1)cout<<ma;
    else if(m==n)cout<<mb;
    else cout<<0;
    return 0;
}
