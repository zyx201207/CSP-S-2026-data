#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long l;
    char ch;
    string s;
    for(int i=1;i<=n;i++){
        cin>>l>>ch;
        for(int j=1;j<=l;j++){
            s=s+ch;
        }
    }
    long long sum=0;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
