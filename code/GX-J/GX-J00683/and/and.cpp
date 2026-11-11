#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,c,m=0;
    cin>>n>>c;
    int sum[n];
    for(int i=0;i<n;i++){
        cin>>sum[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a=sum[i] and sum[j];
            if(a>m){
                m=a;
            }
        }
    }
    cout<<m;
    return 0;
}
