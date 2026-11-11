#include<bits/stdc++.h>

using namespace std;

long long n;
string s;
long long cnt=0;

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    
    for(long long i=1;i<=n;i++){

        long long a;
        char c;

        cin>>a>>c;
        
        for(long long j=1;j<=a;j++){
            s+=c;
        }

    }

    for(long long i=0;i<=s.size()/2-1;i++){
        if(s[i]!=s[s.size()-1-i]){
            cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}