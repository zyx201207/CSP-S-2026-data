#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    cin>>a;
    int b[a];
    char c[a];
    for(int i=0;i<a;i++){
        cin>>b[i]>>c[i];
    }

    string d;
    for(int i=0;i<a;i++){
        for(int j=0;j<b[i];j++){
            d=d+c[i];
        }
    }
    int ans=0;
    for(int i=0;i*2<d.size();i++){
        if(d[d.size()-i-1]!=d[i]){
            ans=ans+1;
        }
    }
    cout<<ans;
    return 0;
}
