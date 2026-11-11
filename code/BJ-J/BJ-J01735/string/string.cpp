#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        int a;
        char b;
        cin>>a>>b;
        for(int j=0;j<a;j++){
            s[j]=b;
        }
    }
    long long ans=0;
    long long l=0,r=s.length()-1;
    while(l<r){
        if(s[l]!=s[r]){
            ans++;
        }
        l++;
        r--;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
