#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string x="";
    int n,l=0;
    cin>>n;
    for (int i=0;i<n;i++){
        int x1;
        char x2;
        cin>>x1>>x2;
        for (int j=0;j<x1;j++){
            x+=x2;
        }
    }
    for (int i=0,j=x.size()-1;i>=0,i<x.size();i++,j--){
        if (x[i]!=x[j]){
            x[j]=x[i];
            l++;
        }
    }
    cout<<l;
    return 0;
}

