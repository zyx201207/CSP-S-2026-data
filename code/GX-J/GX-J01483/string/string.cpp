#include<bits/stdc++.h>
using namespace std;
long long n,m,a[4e9],dif[4e9],q=1,ans=1,ant;
int main(){
    cin>>n;
    while(n--){
        char a;
        cin>>m>>a;
        ans+=m;
        dif[q]+=a;
        dif[ans]-=a;
        for(int i=q;i<=m+1;i++){
            a[i]=dif[i]+a[i-1];
        }
        q=ans;
    }
    if(ans%2==1){
        long long b=ans/2+1;
        for(int i=1,j=ans;i<b,j<=b;i++,j--){
            if(a[i]!=a[j])ant++;
        }
    }else{
        long long b=ans/2;
        for(int i=1,j=ans;i<b,j<=b;i++,j--){
            if(a[i]!=a[j])ant++;
        }
    }
    cout<<ant;
    return 0;
}