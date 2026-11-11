
#include <bits/stdc++.h>
using namespace std;

long long n,sum;
string s;
string re(string m){
    string k;
    for(int i=m.size()-1;i>=0;i--){
        k+=m[i];
    }
    return k;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        string c;
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    sum=s.size()/2;
    if(s==re(s)){
        cout<<0;
        return 0;
    }
    for(int i=0;i<s.size()/2;i++){
        for(int j=s.size()-1;j>=s.size()/2;j--){
            if(s[i]==s[j]) sum--;

        }
    }
    cout<<sum;
    return 0;
}

