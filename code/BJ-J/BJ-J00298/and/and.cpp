#include<bits/stdc++.h>
using namespace std;
int a[999999];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,cnt=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>cnt){
            cnt=a[i];
        }
    }
    cout<<cnt;
    return 0;
}
