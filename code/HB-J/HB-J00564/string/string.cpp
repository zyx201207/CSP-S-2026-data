#include <bits/stdc++.h>
using namespace std;
int a[1000000];
char ch[1000000];
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    string s;
    long long p=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
        p+=a[i];
        for(int j=1;j<=a[i];j++){
            s+=ch[i];
        }
    }
    string s1=s.substr(s.size()-(int)s.size()/2);
    //cout<<s<<endl;
    long long sum=0;
    for(int i=p;i>(p+1)/2;i--){
           // cout<<s[i-1]<<' '<<s1[p-i]<<endl;
        if(s[i-1]!=s1[p-i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
