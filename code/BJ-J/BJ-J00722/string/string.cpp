#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n;
    cin>>n;
    string a;
    int aa;
    char cc;
    long long cnt=0;
    for(int i=0;i<n;i++){
        cin>>aa;
        cin>>cc;
        for(int j=0;j<aa;j++){
            a+=cc;
        }
    }
    long long c=a.length();
    for(int i=0;i<c/2;i++){
        if(a[i]!=a[c-i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
