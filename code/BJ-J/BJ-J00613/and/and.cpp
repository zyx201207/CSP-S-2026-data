#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,a[100004]={},m;
    cin>>n>>m;
    long long dab=0;
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        a[i]=x;
        dab=max(dab,x);
    }
    if(m==1){
        cout<<dab;
    }else{
    int da=0;
    for(int i=1;i<=n;i++){
        int v=a[i];
        for(int k=1;k<=m;k++){
            if(i+k<=n){
            v=v&a[i+k];
            }
        }
        if(v>da){
                da=v;
        }
    }
    cout<<da;
    }
    return 0;
}
