#include<bits/stdc++.h>
using namespace std;
string activities(int a,char b,string c){
    for(int i = 1;i<=a;i++){
        c+=b;
    }
    return c;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a,ah=0,oh=0;
    long long hh[200001];
    char nh[200001];
    string jh;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>hh[i]>>nh[i];
        ah+=hh[i];
        jh=activities(hh[i],nh[i],jh);
    }
    for(int i = 0;i<ah/2;i++){
        if(jh[i]!=jh[ah-i-1]){
            oh++;
        }
    }
    cout<<oh;
    return 0;
}
