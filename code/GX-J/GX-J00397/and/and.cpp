#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ma,k=0;
    cin>>n>>m;
    int a[100000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    while(1){
        ma=a[0];
        for(int i=0;i<n;i++){
            if(a[i]>ma){
                ma=a[i];
                k=i;
            }
        }

        if(m==1)break;
        else {
            m=m-1;
            a[k]=0;
        }
    }
    cout<<a[k];
    return 0;
}

