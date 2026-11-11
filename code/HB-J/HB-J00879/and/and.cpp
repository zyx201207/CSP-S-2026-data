#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],man;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int c=1;c<=n;c++){
        cin>>a[c];
    }if(m==1){
        sort(a+1,a+n+1);cout<<a[n];return 0;
    }else if(m==2){
        for(int c=1;c<=n;c++){
            for(int g=1;g<=n;g++){
                if(c==g)continue;
                man=max(a[c]&a[g],man);
            }
        }
    }cout<<man;
    return 0;}
