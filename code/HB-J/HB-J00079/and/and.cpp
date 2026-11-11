#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        int maxn=0;
        for(int i:a){
            maxn=max(maxn,i);
        }
        cout<<maxn;
    }
    else{
        int maxn=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int now=a[i]&a[j];
                maxn=max(maxn,now);
            }
        }
        cout<<maxn;
    }
    return 0;
}
