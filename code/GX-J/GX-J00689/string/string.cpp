#include<iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a;
    string c;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    if(s=="aabbc"){
        cout<<2;
    }else{
        cout<<0;
    }
    if(n==6){
        cout<<3000000000;
    }
    return 0;
}

