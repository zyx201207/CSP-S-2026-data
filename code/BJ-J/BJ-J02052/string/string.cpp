#include<bits/stdc++.h>
using namespace std;

long long n,sum=0,sz=0;
char c[200005];
string s,s1;

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>c[i];
        s+=c[i];
    }
    s1=reverse(s.begin(),s.end());
    if(s1==s) {
        cout<<0;
        return 0;
    }
    sz=s.size();
    sz/=2;
    for(int i=0;i<sz;i++){
        if(s[i]!=s1[i]){
            sum++;
        }
    }
    cout<<sum;

    return 0;
}
