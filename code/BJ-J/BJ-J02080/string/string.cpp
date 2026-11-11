#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s="";
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        string b;
        cin>>a>>b;
        for(int j=0;j<a;j++){
            s+=b;
        }
    }
    int sum=0;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
