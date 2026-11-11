#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct str{
    int a;
    char st;
};
long long ans;
int n;
string ss;
str s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i].a>>s[i].st;
        for(int j=0;j<s[i].a;j++){
            ss+=s[i].st;
        }
    }
    for(int i=0;i<(int)ss.size()/2;i++){
        if(ss[i]!=ss[ss.size()-1-i]) ans++;
    }
    cout<<ans;
    return 0;
}

