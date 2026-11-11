#include<bits/stdc++.h>
using namespace std;
int n,a[2000010],ans;
string c[2000010],d;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            d+=c[i];
        }
    }
    string b=d;
    reverse(d.begin(),d.end());
    if(b==d){
        cout<<0;
        return 0;
    }
    for(int i=0;i<d.size();i++){
        if(d[i]==b[i]){
            d[i]='.',b[i]='.';
        }
    }
    for(int i=0;i<d.size();i++){
        if(d[i]!='.'){
            ans++;
        }
    }
    cout<<ans/2;
    return 0;
}
