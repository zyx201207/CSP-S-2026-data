#include<bits/stdc++.h>
using namespace std;
int n;
int check(string s){
    int sum=0;
    int len=s.length()-1;
    for(int i=1;i<=len/2;i++){
        if(s[i]!=s[len-i+1]){
            sum++;
        }
    }
    return sum;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    string s1;
    for(int i=1;i<=n;i++){
        int num;
        char c;
        cin>>num>>c;
        for(int j=1;j<=num;j++){
            s1+=c;
        }
    }
    s1=' '+s1;
    int ans=check(s1);
    cout<<ans;
    return 0;
}
