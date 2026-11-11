#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m,z=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin>>x>>y;
        for(int j=1;j<=x;j++){
            a+=y;
        }
    }
    m=a.size();
    for(int i=0;i<m/2+1;i++){
        if(a[i]!=a[m-i-1]){
            z++;
        }
    }
    cout<<z;
    return 0;
}

