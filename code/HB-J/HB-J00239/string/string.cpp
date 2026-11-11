#include <bits/stdc++.h>
using namespace std;
string s;
bool ishuiwen(){
    int l=0,r=s.size()-1;
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
int huiwen(){
    int l=0,r=s.size()-1,ans=0;
    while(l<r){
        if(s[l]!=s[r]){
            ans++;
        }
        l++;
        r--;
    }
    return ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        char c;
        cin>>c;
        while(j--) s+=c;
    }
    if(ishuiwen()){
        cout<<0;
        return 0;
    }else{
        cout<<huiwen();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
