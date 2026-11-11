// redirected? yes
// undebugged? yes

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

//#define debug // redirected when off

const size_t MAXL=2e7+3;
int dp[MAXL];

bool itis(const string& s){
    for(int i=0;i<s.size()/2;++i)if(s[i]!=s[s.size()-i-1])return false;
    return true;
}

int main(){
    #ifndef debug
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif // debug
    freopen("string.in","r",stdin);

    int n;
    cin>>n;
    string str;
    for(int i=0;i<n;++i){
        int a;
        char c;
        cin>>a>>c;
        for(int j=0;j<a;++j)str.push_back(c);
    }

    if(itis(str)){
        cout<<0<<'\n';
        return 0;
    }

//    cout<<str;
    memset(dp,0x3f,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<str.size();++i){
        if(str[i]==str[i-1]){
            dp[i]=min(dp[i],dp[i-1]);
        }
        else dp[i]=min(dp[i],dp[i-1]+1);
    }

//    for(int i=0;i<str.size();++i)
//        cout<<dp[i]<<' ';
//    cout<<'\n';

    cout<<dp[str.size()-1]<<'\n';
    return 0;
}
