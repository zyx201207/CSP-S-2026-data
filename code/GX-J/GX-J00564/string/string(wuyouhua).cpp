#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,l=0;// l  CHANG DU:10*9 * 2*10*5
    string s="";
    cin>>n;
    long long g=0;// GAI BIAN:10*9 * 10*5
    for(int i=0;i<n;i++){
        int a;
        char b;
        cin>>a>>b;
        l+=a;
        for(int c=0;c<a;c++) s=s+b;
    }
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-i-1]) g++;                 // YOU HUA!!!!!!
    }
    cout<<g;
    return 0;
}
