#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,x,c=0;
    cin>>n;
    string r1="";
    char r;
    for(long long i=1;i<=n;i++){
        cin>>x>>r;
        for(long long j=1;j<=x;j++){
            r1+=r;
        }
    }
    long long L=0,R=r1.size()-1;
    while(L<=R){
        if(r1[L]!=r1[R]){
            c++;
        }
        L++;
        R--;
    }
    cout<<c<<endl;
    return 0;
}
