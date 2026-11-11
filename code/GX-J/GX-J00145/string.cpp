#include <bits/stdc++.h>
using namespace std;
int b[100005];
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int n,a,x=0,y=0;
    char c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i]>>c;
    }
    for(int i=1;i<=n;i++){
        if(b[i]<=b[i+1]){
            cout<<b[i];
        }else if(b[i]>b[i+1]) cout<<b[i+1];
    }
    return 0;
}

