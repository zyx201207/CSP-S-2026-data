#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string6.in","r",stdin);
    freopen("string.out","w",stdout);
    string a;
    char b;
    int n,x,sam=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>b;
        for(int j=0;j<x;j++){
            a=a+b;
        }
    }
    for(int i=0;i<a.size()/2;i++){
        if(a[i]!=a[a.size()-i]){
                sam++;
           }
    }
    cout<<sam;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
