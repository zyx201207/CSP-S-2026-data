#include<iostream>
#include<string>
using namespace std;
string s="";
int t;
int huiwen(){
    int ans=0;
    for(int i=0;i<=(s.size()-1)/2;i++){
        int l=i,r=s.size()-i-1;
        if(s[l]!=s[r])ans++;
    }
    return ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        int n;
        char a;
        cin>>n>>a;
        while(n--)s+=a;
    }
    cout<<huiwen();
    return 0;
}

