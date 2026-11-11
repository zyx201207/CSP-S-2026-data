#include<bits/stdc++.h>
using namespace std;
int ans;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    if(m==1){
        sort(a-1,a+n-1);
        cout<<a[n-1];
    }else if(m==2){
        sort(a-1,a+n-1);
        ans=a[n-1];
        for(int i=m-2;i>=0;--i){
            ans&=a[i];
        }
        cout<<ans;
    }else{
        sort(a-1,a+n-1);
        cout<<a[n-1-m];
    }
    return 0;
}
