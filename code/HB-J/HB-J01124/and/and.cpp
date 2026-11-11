#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,max1=0;
    cin>>n>>m;
    int j=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>max1){
            max1=a[i];
        }
    }
    if(m==1){
        cout<<max1;
        return 0;
    }
    int max=0;
    while(m>1){
        j=0;
        for(int k=n-1;k>0;k--){
            for(int y=0;y<k;y++){
                b[j]=a[y]&a[k];

            }
        }
    m--;
    }
    j=0;
        for(int k=n-1;k>0;k--){
            for(int y=0;y<k;y++){
                b[j]=a[y]&a[k];
                if(b[j]>max){
                    max=b[j];
                }
            }
        }
    cout<<max;
    return 0;
}
