#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int num,n;
char d;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>num>>d;
        for(int i=0;i<num;i++){
            s+=d
        }
        sum+=num;
    }
    int cnt=0
    for(int i=0;i<(n+1)/2;i++){
        if(s[i]!==s[sum-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
