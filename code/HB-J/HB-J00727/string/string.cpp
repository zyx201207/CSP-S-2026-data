#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    cin>>n;
    char a;
    string s;
    for(int i=1;i<=n;i++){
        cin>>m>>a;
        for(int g=1;g<=m;g++){
            s=s+a;
        }
    }
    string l=s;
    int u=0;
    reverse(l.begin(),l.end());
    string m1=l;
    for(int i=0;i<s.length();i++){
        reverse(m1.begin(),m1.end());
        if(l[i]!=m1[i]){
            l[i]=m1[i];
            u++;
            i=0;
        }
        m1=l;

    }
    cout<<u;

    return 0;
}
