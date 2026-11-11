#include <bits/stdc++.h>
using namespace std;
int S=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string a;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin >> x >> y;
        for(int j=0;j<x;j++){
            a+=y;
        }
    }
    string b;
    int cd=a.size();
    if(cd%2==0){
        for(int i=0;i<cd/2;i++){
            b+=a[i];
        }
    }
    else {
        for(int i=0;i<=cd/2;i++){
            b+=a[i];
        }
    }

    string c;
    for(int i=0;i<=cd/2-1;i++){
        c+=a[i];
    }
    reverse(c.begin(),c.end());
    b+=c;
    for(int i=0;i<cd;i++){
        if(a[i]!=b[i]){
            S++;
        }
    }
    cout << S;
    return 0;
}
