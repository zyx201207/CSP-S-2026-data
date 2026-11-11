#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int s=0;
    int a[1000];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    } for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                if(a[i]!=a[j]){
                    int x=a[i];
        int b=a[j];
                int c=x&=b;
        s=max(c,s);
                }

    }}
    cout<<s;
    return 0;
}
