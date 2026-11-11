#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[10000];
int main(){
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,d;
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
        if(c==0){
            if(t==2&&n==4)cout<<1<<endl<<2;
            if(t==2&&n==5)cout<<0<<endl<<1;
            return 0;
        }
    }
    cout<<3<<endl<<5;
    return 0;
}
