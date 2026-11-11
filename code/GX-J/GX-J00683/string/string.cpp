#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string S="";
    int n;
    long long step=0;
    cin>>n;
    for(int i=0;i<n;i++){
        long long m;
        string a;
        cin>>m>>a;
        for(long long j=m;j>0;j--){
            S+=a;
        }
    }
    long long sum=S.size();
    for(long long i=0;i<sum/2;i++){
        if(S[i]!=S[sum-1-i]){
            step++;
        }
    }
    cout<<step;
    return 0;
}
