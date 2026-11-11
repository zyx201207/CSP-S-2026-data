#include <bits/stdc++.h>
using namespace std;
string a;
int main(){
    freopen("string6.in","r",stdin);
    freopen("string6.out","w",stdout);
    int n,t=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        char y;
        cin>>x>>y;
        t+=x;
        while(x!=0){
            a+=y;
            x--;
        }
    }
    int l=0;
    for(int i=0;i<t;i++){
        if(a[i]!=a[t-i-1]){
            a[t-i-1]=a[i];
            l++;
        }
    }
    cout<<l;
    return 0;
}