#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    long long sum=0;
    for(int i=0;i<n;i++){
        long long a;
        string c;
        cin>>a>>c;
        sum+=a;
        for(int j=0;j<a;j++){
            s+=c;
        }
    }
    long long cnt=0;
    for(int i=0;i<sum/2+1;i++){
        if(s[i]!=s[s.size()-1-i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
