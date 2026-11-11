#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[1000000],sum=0;
    char c[1000000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    if(n==1 || sum==1){
        cout<<0;
        return 0;
    }else if(n==2 && c[0]==c[1]){
        cout<<0;
        return 0;
    }else if(n==2 && c[0]!=c[1]){
        cout<<1;
        return 0;
    }else if(sum%2==0){
        cout<<sum/2;
    }else{
        cout<<(sum-1)/2;
        return 0;
    }
    return 0;
}
