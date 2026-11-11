#include <bits/stdc++.h>
using namespace std;
struct str{
    long long num;
    char c;
}a[200005];
int n;
long long ans;
str b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    int tmp;
    for(int i=1, j=0;i<=n;i++){
        cin >> a[i].num >> a[i].c;
        if(a[i].c!=b[j].c){
            j++;
            b[j].c=a[i].c;
            b[j].num=a[i].num;
        }else b[j].num+=a[i].num;
        tmp=j;
    }
    n=tmp;
    if(n==1){
        cout << 0;
        return 0;
    }
    string x=" ";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i].num;j++){
            x+=a[i].c;
        }
    }
    for(int i=1;i<=x.size()/2;i++){
        if(x[i]!=x[n+1-i]) ans++;
    }
    cout << ans;
    return 0;
}
