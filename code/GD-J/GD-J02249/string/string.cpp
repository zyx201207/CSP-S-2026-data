#include<bits/stdc++.h>
using namespace std;
string S,S1;
char m;
long long L,n,a,cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>a>>m;
        L+=a;
        while(a--) S+=m;
    }
    //cout<<S;
    for(long long i=0;i<L/2;i++){
        if(S[i]!=S[L+1-i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
