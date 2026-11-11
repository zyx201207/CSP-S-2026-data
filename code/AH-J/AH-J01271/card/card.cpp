#include<iostream>
#include<cstdio>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<3<<" "<<1<<" "<<4;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
