#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    char S[110000];
    int cnt=0;
    long long ccnt=0;
    for(int i=0;i<n;i++){
        long long k;
        char a;
        cin>>k>>a;
        ccnt+=k;
        for(int j=0;j<k;j++){
            S[cnt]=a;
            cnt++;
        }
    }
    int I=0,J=ccnt-1;
    int ans=0;
    while(I<J){
        if(S[I]!=S[J]) ans++;
        I++;
        J--;
    }
    cout<<ans;
    return 0;
}
