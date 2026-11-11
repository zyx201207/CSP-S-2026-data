#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        long long a;
        string temp;
        char c;
        cin>>a>>c;
        for(long long i=0;i<a;i++){
            s+=c;
        }
    }
    for(long long i=0;i<s.size()/2;){
        for(long long j=s.size()-1;j>=s.size()/2+1;){
            if(s[i]!=s[j]){
                cnt++;
            }
            i++;
            j--;
        }
    }
    cout<<cnt;
    return 0;
}
