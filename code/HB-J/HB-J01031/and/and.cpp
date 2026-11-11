#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    if(m == 1){
        int as = 0;
        for(int i = 1;i<=n;i++){
            if(a[i]>as){
                as = a[i];
            }
        }
        cout<<as;
        return 0;
    }
    int as = 0;
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            int pre = a[i]&a[j];
            if(pre>as){
                as = pre;
            }
        }
    }
    cout<<as;







    return 0;
}
