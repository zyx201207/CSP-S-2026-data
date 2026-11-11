#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
char a[];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int x=0;
    for (int i=1;i<=n;i++){
        cin>>m>>a;
        x+=m;
    }
    cout<<x/2;
    return 0;
}
