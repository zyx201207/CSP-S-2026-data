#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m=0,t=0,cnt=0;
    cin>>n;
    string c,d;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        m+=a[i];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<a[i];j++){
            d[t]=c[i];
            t++;
        }
    }
    for(int i=m/2-1;i>=0;i--){
         if(d[i]!=d[m-1-i]){
               cnt++;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}