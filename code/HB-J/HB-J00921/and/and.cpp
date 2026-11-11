#include<bits/stdc++.h>
using namespace std;
int a,b,c,n;
string  x,y,z;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c>>x;
        string l = x;
        for(int j = 0;j<c;j++){
            x = x + l;
        }
        y = y + x;
    }
    int m = y.size();
    for(int i = m;i<m/2;i--){
        if(y[n]!=y[i]){
            b++;
        }
    }
    cout<<b;
    return 0;
}
