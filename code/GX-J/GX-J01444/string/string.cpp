#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum,sp=0,su;
    string num,S,RS;
    char a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>sum>>num;
        for(int j=0;j<sum;j++){
            S+=num;
        }
    }
    RS=S;
    reverse(RS.begin(),RS.end());
    su=S.size()-1;
    for(int i=0;i<RS.size();i++){
        if(RS[i]!=S[i]){
            RS[i]=S[i];
            S[su]=RS[i];
            sp++;
        }
        su--;
    }
    cout<<sp;
    return 0;
}
