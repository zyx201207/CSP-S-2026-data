#include<bits/stdc++.h>
using namespace std;
string s="";
long long n,sum,cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        long long a;
        char c;
        cin>>a>>c;
        sum+=a;
        while(a--){
            s+=c;
        }
    }
    long long cnt1=0,cnt2=s.size()-1;

    sum/=2;
    for(long long i=0;i<sum;i++){
        if(s[cnt1]!=s[cnt2]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
