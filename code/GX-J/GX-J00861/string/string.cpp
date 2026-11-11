#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,num=0,nnum=0;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        char b;
        cin>>b;

        for(int j=0;j<a;j++){
            s[num]=b;
            num++;
        }
    }
    int l=0,r=num-1;

    while(l<r){
        if(s[l]!=s[r]){
            nnum++;

        }
        l++;
        r--;

    }
    cout<<nnum;





































     return 0;
}














