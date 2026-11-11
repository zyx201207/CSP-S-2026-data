#include<bits/stdc++.h>
using namespace std;;
int n,a[200001],l,r,x,y,z,cnt;
char b[200001];
int main(){
    freopen(string.in,"r",stdin);
    freopen(string.out,"w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    l=1;r=n;
    while(l<r){
        x=a[l];
        y=a[r];
        if(b[l]!=b[r])cnt+=min(x,y);
        z=min(x,y);
        a[l]-=z;x-=z;
        a[r]-=z;y-=z;
        if(x==0)l++;
        if(y==0)r--;
    }
    cout<<cnt;
    return 0;
}
