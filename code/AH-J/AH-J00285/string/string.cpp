#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s;
bool f(string s){
    bool f=1;
    long long nn=s.size(),x=s.size()/2;
    for(long long i=0;i<=x;i++){
        if(s[i]!=s[nn-i-1]){
            ans++;
            f=0;
        }
    }
    if(f==1){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n!=1){
        for(long long i=1;i<=n;i++){
            long long a;
            char c;
            cin>>a>>c;
            for(int j=1;j<=a;j++){
                s+=c;
            }
        }
        if(f(s)){
            cout<<0;
        }else{
            cout<<ans;
        }
    }else{
        for(long long i=1;i<=n;i++){
            long long a;
            char c;
            cin>>a>>c;
        }
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
