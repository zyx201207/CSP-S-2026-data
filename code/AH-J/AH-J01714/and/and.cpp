///小X和小R能不能去死啊！！！
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int t=-1,s=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s=max(s,a[i]);
    }
    if(m==1){
        cout<<s;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            t=max(t,(a[i]&a[j]));
        }
    }
    cout<<t;
    fclose(stdin),fclose(stdout);
    return 0;
}
///求AC！！！求AC！！！求AC！！！
///求AC！！！求AC！！！求AC！！！
///求AC！！！求AC！！！求AC！！！
