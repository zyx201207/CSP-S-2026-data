#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int s;
    string a,u,m;
    m=a;
    cin>>s;
    for(int i=1;i<=s;i++){
        int q;
        char w;
        cin>>q>>w;
        for(int j=q;j>0;j--){
            a[j]=w;
        }
    }

    if(m==a){
        cout<<"0";
    }

    }
