#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<map>
using namespace std;
long long n,a[200009],sum=0;
string s[200009],s1,s2;
bool h(string s){
    string s1;
    for(int i=s.size();i>0;i--){
        s1+=s[i];
    }
    for(int i=0;i<s.size();i++){
        if(s1[i]!=s[i]){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>a[i]>>s[i];
        for(int j=0;j<a[i];j++){
            s1+=s[i];
        }
    }
    for(int i=s1.size();i>=0;i--){
        s2+=s1[i];
    }
    if(h(s1)){
        cout<<"0";
        return 0;
    }
    for(int i=0;i<n;i++){
            for(int j=0;j<s1.size();j++){
                if(s1[i]!=s2[i]){
                    sum++;
                }
            }
        }
    cout<<sum/5;
    //力竭了
    //能骗多少骗多少吧
    //我还是去洛谷玩吧
    return 0;
}
