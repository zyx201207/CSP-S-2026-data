#include<bits/stdc++.h>
using namespace std;
int n,m,c=0;
char p,q;
string k;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> m >> p;
        for(int j=1;j<=m;j++){
            k.push_back(p);
        }

    }
    int l = k.size();
    for(int i=0;i<=l/2;i++){
        if(k[i]!=k[l-i-1]){
            c++;
        }
    }
    cout << c;
    return 0;
}
