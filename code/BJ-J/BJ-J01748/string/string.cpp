#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum=0;
    string s,s1,s2;
    cin>>n;
    for(int i=1;i<=n;i+=1){
        long long a;
        string aa;
        cin>>a>>aa;
        for(int j=0;j<a;j+=1){
            s+=aa;
        }
    }
    for(int i=0;i<s.size()/2;i+=1){
        s1+=s[i];
    }
    for(int i=s.size()-1;i>(s.size()-1)-(ceil(s.size()/2));i-=1){
        s2+=s[i];
    }
    for(int i=0;i<s.size()/2;i+=1){
        if(s1[i]!=s2[i]){
            sum+=1;
        }
    }
    cout<<sum;
}
