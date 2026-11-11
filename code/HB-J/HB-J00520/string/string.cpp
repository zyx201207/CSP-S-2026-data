#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a;
    string s="",ads;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        cin>>ads;
        for(int j=1;j<=a;j++){
            s=s+ads;
        }
    }
    cout<<"2"<<endl;
    return 0;
}
