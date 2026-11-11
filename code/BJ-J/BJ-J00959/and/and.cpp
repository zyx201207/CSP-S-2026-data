#include<bits/stdc++.h>
using namespace std;
int a[200003];
bool cmp(int a,int b){
    return a>b;
}
int main(){//abbcccddddcccba
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    int andn=a[0];
    //cout<<andn<<" ";
    for(int i=1;i<=m-1;i++){
        //cout<<a[i]<<" ";
        andn=andn&a[i];
    }
    cout<<andn;
    return 0;
}