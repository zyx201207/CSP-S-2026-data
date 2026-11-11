#include<bits/stdc++.h>
using namespace std;
long long n,a,js;
string s;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        while(a--){
            s+=c;
        }
    }
    long long l=s.size();
    for(int i=0;i<(l+1)/2;i++){
        if(s[i]!=s[l-i-1]) js++;
    }
    cout<<js<<endl;
    return 0;
}
