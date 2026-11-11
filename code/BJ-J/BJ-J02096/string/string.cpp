#include<bits/stdc++.h>
using namespace std;
const long long N=2e9+5;
int n,s=0;
char a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }if(n==2){
        int s=0,d=0;
        char f,g;
        cin>>s>>f>>d>>g;
        if(f==g){
            cout<<0;
            return 0;
        }
        cout<<min(s,d);
        return 0;
    }
    for(int i=1;i<=n;i++){
        int ai;
        char ci;
        cin>>ai>>ci;
        s+=ai;
    }cout<<s/2;
    return 0;
}

