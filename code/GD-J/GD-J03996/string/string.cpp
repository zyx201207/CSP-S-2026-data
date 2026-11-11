#include <bits/stdc++.h>
using namespace std;
int n,a[200005],q,p;
string c,e;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=0;i<c.size();i++){
        for(int j=0;j<a[i];j++){
            e+=c[i];
            p++;
        }
    }
    for(int i=0;i<p/2;i++){
        if(e[i]!=e[p-i-1]){
            q++;
        }
    }
    cout<<q;
}
