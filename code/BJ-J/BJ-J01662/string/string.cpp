#include<bits/stdc++.h>
using namespace std;
int n,a;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>a>>c;
        while(a--){
            s=s+c;
        }
    }
    long long ans=0;
    int i=0;
    int j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]){
            ans++;
        }
        i++;
        j--;
    }
    cout<<ans;
    return 0;
}
