#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m,v=0,b=0;
    string a,x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> m>> x;
        for(int j=0; j<m; j++) a[v+j]=x;
        v=m;
    }
    if (a.cize()%2==1){
        for(int i=0; i<(a.size()-1)/2; i++){
            if(a[i]!=a[a.size()-i])b++;
        }
    }
    else
        for(int i=0; i<a.size()/2; i++){
            if(a[i]!=a[a.size()-i])b++;
        }
    cout << b;
    return 0;
}
