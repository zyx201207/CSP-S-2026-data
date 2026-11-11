#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],andsum;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxv=-10000;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                andsum=a[i]&a[j];
                if(andsum>maxv){
                    maxv=andsum;
                }
            }
        }
    }
    cout<<maxv;
    return 0;
}
