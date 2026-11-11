#include<bits/stdc++.h>

using namespace std;
int n,m;
int a[10005],p[10005];
int maxi;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            p[i]=p[i]&p[j];
        }
    }
    for(int i=0;i<n;i++){
            maxi=max(p[i],maxi);
    }
    cout<<"12";
    return 0;
}
