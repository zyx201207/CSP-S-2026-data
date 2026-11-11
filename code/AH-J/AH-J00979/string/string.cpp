#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char a;
    int n,k=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        cin>>a;
        for(int l=0;l<x;l++){
            s+=a;
        }
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            k++;
        }
    }
    cout<<k;



    return 0;
}
