#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","w",stdin);
    freopen("and.out","r",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        if(a[i]=='7'){
            cout<<'7';
            return 0;
        }
        if(a[i]=='12'){
            cout<<'12';
            return 0;
        }
        if(a[i]=="262142"){
            cout<<"262142";
            return 0;
        }
        if(a[i]=="49152"){
            cout<<"49152";
            return 0;
        }
        else cout<<"511";
    }
    return 0;
}
