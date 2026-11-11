#include <bits/stdc++.h>
using namespace std;

int main(){
    frespen("and.in","r",stdin);
    frespen("and.out","w",stdout);
    int a[1005],b[1005]={};
    int n,m;
    cin >>n >> m;
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            b[j]=a[i]&a[j];

        }

        }
    int f=0;
    for(int i=0;i<n*n;i++){
        f=max(f,b[i]);


    }

    cout<<f;

return 0;
}
