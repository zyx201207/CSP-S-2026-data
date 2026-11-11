#include<bits/stdc++.h>
using namespace std;
unsigned long long n;
unsigned long long a[200004];
char c[200004];
unsigned long long ans=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(unsigned long long i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    unsigned long long a_i=0,a_j=n-1;
    unsigned long long to_i=0,to_j=0;
    while(a_i<a_j){
        if(a[a_i]<=to_i){
            a_i++;
            to_i=0;
            continue;
        }
        if(a[a_j]<=to_j){
            a_j--;
            to_j=0;
            continue;
        }
        unsigned long long len=min(a[a_i]-to_i,a[a_j]-to_j);
        if(c[a_i]!=c[a_j]){
            ans+=len;
        }
        to_i+=len,to_j+=len;
    }
    cout<<ans;
}
