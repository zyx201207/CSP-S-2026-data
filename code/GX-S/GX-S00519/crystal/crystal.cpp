#include<bits/stdc++.h>
using namespace std;
long a[5000000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,jsq=1,qq=0,sw=0,big=1;
    long long m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        sw=n-i-2;
        if(sw<0) break ;
        while(qq<=m){
            qq+=a[n-i-1]-a[sw];
            if(qq>m){
                big=max(jsq,big);
                break;
            }
            else{
                jsq++;
                big=max(jsq,big);
                sw--;
                if(sw<0) break ;
            }

        }

        qq=0;
        jsq=1;
    }
    if(big>n){
        big=n;
    }
    cout<<big;
    return 0;
}
