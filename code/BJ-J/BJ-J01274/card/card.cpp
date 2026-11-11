#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int n,m,j=0;
string s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=1;i<=m;i++){
        int jl=0;
        for(int x=0;x<n;x++){
            if(s[x]==i+'0') jl=x;
        }
        cout<<jl<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
