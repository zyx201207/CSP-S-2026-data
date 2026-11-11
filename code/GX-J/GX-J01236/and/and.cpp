#include<bits/stdc++.h>
using namespace std;
int n,m,a[20000005],b;


int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
        int z1=1,z2=2;
    for(int i=1;i<=n;i++){

        for(int j=i;j<=n;j++){
            if(a[i] and a[j]>z1 and z2){
                z1=a[i];
                z2=a[j];
            }
        }
    }
    cout<<z1 and z2;
    return 0;
}

