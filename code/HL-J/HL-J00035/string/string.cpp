#include<bits/stdc++.h>
using namespace std;
long long n,a,f;
char b;
string s,s1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        for(int i=1;i<=a;i++){
            s+=b;
        }
    }

    for(int i=s.size()-1;i>=0;i--){
            s1+=s[i];
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s1[i])f++;
    }
    cout<<f;
    fclose(stdin);
    fclose(stdout);
    return 0;

}
