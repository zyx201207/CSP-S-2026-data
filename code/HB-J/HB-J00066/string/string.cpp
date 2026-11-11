#include <bits/stdc++.h>
using namespace std;
//RP++
const int MAXN=2*1e5+5;
int n;
struct edge{
    int len;
    char ch;
}a[MAXN];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //half,l/r
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].len>>a[i].ch;
    }


    return 0;
}
