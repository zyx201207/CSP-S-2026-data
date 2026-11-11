#include<bits/stdc++.h>
using namespace std;
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int a,c=0,n;
string b,t="",y="";
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        for(int j=0;j<a;j++){
            t=t+b;
            y=b+y;
        }
    }
    for(int j=0;j<n/2;j++){
        if(t[j]!=y[j]){
            c++;
        }
    }
    cout<<c;
    return 0;
}
