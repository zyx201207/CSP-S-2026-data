#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],c;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(m==1){
        for(int i=1;i<=n;i++){
            c=max(c,a[i]);
        }
        cout<<c;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                c=max(c,a[i]&a[j]);
            }
        }
        cout<<c;
    }
    else
        cout<<511;
    return 0;
}
