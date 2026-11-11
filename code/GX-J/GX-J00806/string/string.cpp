#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n,shu=0;
    string S;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long a;
        string c;
        cin>>a>>c;
        for (int j=0;j<a;j++){
            S.append(c);
        }
    }

    for(int i=0;i<S.size();i++){
        if(S[i]!=S[S.size()-1-i]){
            S[i]=S[S.size()-1-i];
            shu++;
        }
    }

    cout<<shu;

    return 0;
}
