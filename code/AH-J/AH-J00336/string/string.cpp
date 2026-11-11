#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
string s="";
void f(string s){
    int l=0,r=s.size()-1;
    while(l<=r){
        if(s[l]!=s[r]){
            cnt++;
        }
        l++;
        r--;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long a;
        string c;
        cin>>a>>c;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    f(s);
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
