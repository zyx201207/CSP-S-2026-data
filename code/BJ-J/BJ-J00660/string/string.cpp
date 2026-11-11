#include<bits/stdc++.h>
using namespace std;
long long n,a[200009],h,fn;
string c[200009];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    fn=n-1;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    int i=0;
    while(i<fn){
        long long mi=min(a[i],a[fn]);
        if(c[i]!=c[fn]){
            h+=mi;
        }
        a[i]-=mi;
        a[fn]-=mi;
        if(!a[fn]) fn--;
        if(!a[i]) i++;
    }
    cout<<h;
    return 0;
}
