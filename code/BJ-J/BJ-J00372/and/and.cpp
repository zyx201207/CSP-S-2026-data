#include<bits/stdc++.h>
using namespace std;
long long n,m,w,a[100000],s=17179869183;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[j]>a[w]){
                w=j;
            }
        }
        s=s&a[w];
        a[w]=0;
    }
    cout<<s;
    return 0;
}
