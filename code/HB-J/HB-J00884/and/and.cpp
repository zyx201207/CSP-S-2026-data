#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen ("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n;
    cin>>n>>m;
    int a[200005];
    int b[200005]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m=n){
        int k=1;
        for(int i=0;i<n;i++){
            k=k&a[i];
        }
        cout<<k;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n && j!=i;j++){
               int k=a[i]&a[j];
               if(k>b[i]){
                b[i]=k;
               }
        }
    }
    sort(b,b+n);
   cout<<b[n-1];
    fclose(stdin);
    fclosee(stdout);
return 0;}
