#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int L;
    cin>>L;
    string S[L];
    for(int i=0;i<L;i++){
        cin>>S[i];
    }
    for(int j=0;j<L;j++){
        cout<<S[j];
    }
    return 0;
}
