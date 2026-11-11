#include<bits/stdc++.h>
using namespace std;
int a;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    bool flag=0;
    char b;
    cin>>a>>b;
    for(int i=0;i<a;i++){
        s+=b;
    }
    for(int i=1;i<n;i++){
        char c;
        cin>>a>>c;
        if(c!=b){
            flag=1;
        }
        for(int j=0;j<a;j++){
            s+=c;
        }
    }
    if(!flag){
        cout<<0;
        return 0;
    }
    int cnt=0;
    for(long long i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
	return 0;
}
