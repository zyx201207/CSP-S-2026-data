#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
    freopen(string.in,'r',std.in);
    freopen(string.out,'w',std.out);
    int n;
    cin>>n;
    int a[0][n];
    int m=0,o=0;
    char as[0][n];
    string s[10000000];
    for(int i=0;i<=n-1;i++){
        cin>>a[0][i]>>as[0][i];
        for(m=0+m;m<=a[0][i]-1;m++){
            s[m]=as[i];
        }
    }
    if(m%2==1){
        for(int j=m-1;j>=m/2+1;j--)
        for(int i=0;i<=m/2+1;i++)
        if(s[i]!=s[j])
        o++;
    }
    cout<<o;
    return 0;
}
