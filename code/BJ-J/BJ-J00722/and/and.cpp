#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200005]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    if(m==1){
        key=0;
        for(int i=0;i<n;i++){
            if(a[i]>key) key=a[i];
        }
    }
    else if(m==n){
        key=a[0];
        for(int i=0;i<n;i++){
            key&=a[i];
        }
    }
    cout<<key;
    return 0;
}
