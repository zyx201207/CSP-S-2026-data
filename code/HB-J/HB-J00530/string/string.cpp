#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long a[n];
    char c[n];
    long long cnt=1;
    long long j1;
    char w;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        cin>>w;
        for(long long j=cnt  ;j<cnt+a[i];j++){
            j1=j;
            c[j]=w;
        }
        cnt=j1+1;
    }
    string S;
    for(long long i=1;i<cnt;i++){
        S+=c[i];
    }

    long long yiban_q=cnt/2-1;
    string a2=S;
    reverse(a2.begin(),a2.end());
    if(S==a2){
        cout<<0;
        return 0;
    }
    string fz_s,fz_a2;
    for(long long i=0;i<yiban_q;i++){
        fz_s+=S[i];
        fz_a2+=a2[i];
    }
    long long cnt1=0;
    for(long long i=0;i<yiban_q;i++){
        if(fz_a2[i]!=fz_s[i]){
            cnt1++;
        }
    }
    cout<<cnt1;
    return 0;
}
