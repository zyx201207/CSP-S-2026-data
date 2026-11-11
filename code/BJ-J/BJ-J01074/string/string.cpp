#include <bits/stdc++.h>;
using namespace std;
int n;
string s;
long long res;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        int as;
        char c;
        cin>>as>>c;
        while(as--){
            s+=c;
        }
    }
    int len=s.size()/2,alllen=s.size()-1;
    for(int i=0;i<len;i++){
        if(s[i]!=s[alllen-i])res++;
    }
    cout<<res;
    return 0;
}
