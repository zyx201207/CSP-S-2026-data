#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="",x;
    long long n,times,sum=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>times>>x;
        for(long long j=1;j<=times;j++){
            s=s+x;
        }
    }
    long long a=0,b=s.size()-1;
    while(a<b){
        if(s[a]!=s[b]){
            sum++;
        }
        a++;b--;
    }
    cout<<sum;
    return 0;
}
