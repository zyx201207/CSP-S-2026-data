#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int maxz=0;
int main(){
    /*freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int z=a[i]&&a[j];
            if(maxz<z){
                maxz=z;
            }
        }
    }
    cout<<maxz;*/
    long long x,y;
    cin>>x>>y;
    cout<<pow(pow(x,x),pow(y,y));
    return 0;
}
