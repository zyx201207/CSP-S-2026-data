#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt,a[200010],x,y,l,r;
    char b[200010];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    l=1;
    r=n;
    x=a[l];
    y=a[r];
    while(l<r){
        if(x>y){
            if(b[l]!=b[r]) cnt+=y;
            x=x-y;
            r--;
            y=a[r];
        }
        if(y>x){
            if(b[l]!=b[r]) cnt+=x;
            y=y-x;
            l++;
            x=a[l];
        }
        if(y==x){
            if(b[l]!=b[r]) cnt+=x;
            l++;
            r--;
            x=a[l];
            y=a[r];
        }
    }
    cout<<cnt;
    return 0;
}