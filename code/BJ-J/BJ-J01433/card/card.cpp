#include<bits/stdc++.h>
using namespace std;
long long a[2000001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        int ss=3;
        cout<<i+ss<<" ";
        ss+=2;
    }
    return 0;
}