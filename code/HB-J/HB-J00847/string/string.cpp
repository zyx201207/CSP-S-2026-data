#include<bits/stdc++.h>
using namespace std;
char c[1000000000],b[1000000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long cnt=0,m=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        char k;
        cin>>a>>k;
        for(int j=n;j<n+a;j++){
            c[i]=k;
        }
        m+=a;
    }
    for(long long i=0;i<m;i++){
        b[m-i-1]=c[i];
    }
    for(long long i=0;i<m/2;i++){
        if(b[i]!=c[i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
