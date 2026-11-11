#include<iostream>
#include<cstdio>
using namespace std;
int a[200005];


int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<a[n]<<endl;
}

