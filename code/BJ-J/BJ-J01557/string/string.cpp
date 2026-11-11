#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string m="",w="",c[200000]={};
    int n ,a[200000]={},t=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=0;i<n;i++){
        while(a[i]--){
            m += c[i];
        }
    }
    for(int i=0;i<n;i++){
        w[i]=m[n-i];
    }
    for(int i=0;i<n;i++){
        if(m[i]!=w[i]){
            t++;
        }
    }
    cout<<(t+1)/2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
