#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200001];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){

        int maxx=-1;
        for(int i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
        return 0;
    }
    if(m==n){
        int ansss=2147483647;
        for(int i=1;i<=n;i++){
            ansss=ansss&a[i];
        }
        cout<<ansss;
        return 0;
    }
    if(m==2){
        int tk13=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                tk13=max(tk13,a[i]&a[j]);
            }
        }
        cout<<tk13;
        return 0;
    }
    sort(a+1,a+n+1);
    cout<<a[n-m+1];
    return 0;
}
