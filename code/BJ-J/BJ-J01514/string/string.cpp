#include<bits/stdc++.h>
using namespace std;
string ans;
string rans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a;
    cin>>a;
    for(long long i=0;i<a;i++){
        long long io;
        string jia;
        cin>>io>>jia;
        for(long long p=0;p<io;p++){
            ans+=jia;
        }
    }

    long long cnt=0;
    for(long long i=ans.size()-1;i>=0;i--){
        rans+=ans[i];
        cnt++;
    }
    if(rans==ans){
        cout<<0;
        return 0;
    }
    cnt=0;
    for(long long i=0;i<ans.size();i++){
        if(rans[i]!=ans[i]){
            cnt++;
            rans[i]=ans[i];
            ans[ans.size()-1-i]=rans[i];
        }
    }
    cout<<cnt;
    return 0;
}


