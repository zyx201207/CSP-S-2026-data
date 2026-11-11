#include <bits/stdc++.h>
using namespace std;
const long long N=100000005;
long long o[N];
char b[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>o[i]>>b[i];}
    long long ans=0;
    long long c=0,d=n-1;
    for (int i=0;i<N/2;i++){
        if(b[c]!=b[d]){
            ans++;
        }
        c++;
        d--;
    }
    cout <<ans;
    return 0;
}
