#include <bits/stdc++.h>
using namespace std;
int main{
    int n,a,q;
    char c;
    string S[n];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        S[n]+=c;
    }
    for(int j=0;j<=n/2;j++){
        if(S[j]!=S[n-j]){
            q+=1;
            }
		}
    cout<<q/2;
return 0;
}
