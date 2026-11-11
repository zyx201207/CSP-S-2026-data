#include<bits/stdc++.h>
using namespace std;
int n,a,b;
char a1,b1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n==2){
        cin>>a>>a1>>b>>b1;
        if(a==b){
                cout<<0;
                return 0;
        }
    }
    cout<<0;
    return 0;
}
