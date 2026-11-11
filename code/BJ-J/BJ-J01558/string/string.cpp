#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long sum;
string s,s1,s2;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin>>x>>y;
        for(int j=1;j<=x;j++){
            s+=y;
        }
    }
    //cout<<s<<endl;
    long long len=s.size();
    long long zh=len/2;
    long long in=len%2;
    //cout<<len<<' '<<zh<<' '<<in<<endl;
    for(int i=0;i<zh;i++){
        s1+=s[i];
    }
    for(int i=len-1;i>=zh+in;i--){
        s2+=s[i];
    }
    //cout<<s1<<' '<<s2<<endl;
    for(int i=0;i<zh;i++){
        if(s1[i]!=s2[i])sum++;
    }
    cout<<sum;
    return 0;
}
