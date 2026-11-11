#include<bits/stdc++.h>
using namespace std;

struct cc{
    int t;
    char c;
};
int n;
cc a[200005];
long long L;
string tot="a";
bool check(long long num){
    long long change1=0;
    for(long long i = 1;i<=L/2;i++){
        long long opp=L-i+1;
        if(tot[opp]!=tot[i]){
            change1++;
        }
    }
    return change1 <= num;
}
long long check2(){
    long long change1=0;
    for(long long i = 1;i<=L/2;i++){
        long long opp=L-i+1;
        if(tot[opp]!=tot[i]){
            change1++;
        }
    }
    return change1;
}
long long erf(){
    long long l=0,r=L+1;
    while(l<r-1){
        long long mid=l+(r-l)/2;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    return r;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i].t>>a[i].c;
        L+=a[i].t;
        for(int j = 1;j<=a[i].t;j++){
            tot+=a[i].c;
        }
    }
    long long ans=erf();
    if(ans==1){
        if(check2()==0){
            cout<<0;
        }
        else{
            cout<<1;
        }
    }
    else{
        cout<<ans;
    }
    return 0;
}

