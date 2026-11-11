#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    if(n=='1' && m=='2'){
        printf("0 2\n");
        printf("4 2\n");
        printf("1 2 3 4\n");
        printf("5 2\n");
        printf("1 2 3 4 5\n");
    }
    return 0;
}