#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int s[n]={};
    int num=0;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    sort(s+1,s+n+1,cmp);
    num=s[1];
    for(int i=1;i<m;i++){
        num=num&s[i+1];
    }
    cout<<num;
    return 0;
}
