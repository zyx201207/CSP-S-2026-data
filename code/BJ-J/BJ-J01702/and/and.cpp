#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
    return(x>=y);
}

int main (){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int l=1;
    if(a[l]==a[l+m-1]){
        cout<<a[l];
        return 0;
    }
    if(a[1]%2==0){
        int l=1;
        for(int i=1;i<=n-m+1;i++){
            if(a[l]==a[l+m-1]){
                cout<<a[l];
                return 0;
            }
            l++;
        }
    }
    int ans=a[1];
    for(int i=1;i<=m;i++){
        ans=ans&a[i];
    }
    cout<<ans;

}
