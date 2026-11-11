#include<bits/stdc++.h>
using namespace std;
long long  n,m,mx=0;
long long a[300000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i+m<n;i++){
        long long x=0;
        for(int j=0;j<m;j++){

            if(j==0){
                x=a[i];
            }else{
                x=x&a[i+j];
            }
        }
        if(x>mx){
            mx=x;
        }
    }
    cout<<mx;
    /*int x=m&n;
    cout<<x;*/
    return 0;
}
