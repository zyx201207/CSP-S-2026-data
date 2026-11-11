#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,m,ans=0;
string p,ant;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.ont","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        cin>>ant;
        for(int j=0;j<m;j++){
            p += ant;
            ans++;
        }
    }
    //cout<<p<<endl;
    int num=0;
    for(int i=0;i<ans/2;i++){
        if(p[i] != p[ans-i-1]) num++;
    }
    cout<<num;
    return 0;
}
