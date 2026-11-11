#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a,b,c,s1;
    cin>>a>>b>>c>>s1;
    for(int i = 0;i<=a.size();i++){}
        cin>>a[i];
    for(int j = 0;j<=b.size();j++){
        cin>>b[j];
    for(int m = 0;m<=c.size();m++){}
        cin>>c[m];
        c[m] = a[i]+b[j];
        s1.size() = c[m];
    }
    for(int m = 0;m<=c.size();m--){
        if(s1.size() == c[m])
            cout<<"0";
    }


}
