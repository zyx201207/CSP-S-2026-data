#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n==2){
        int b,c;string d,e;cin>>b>>d>>c>>e;
        if(d==e)cout<<0;
        else cout<<abs(b-c);
        return 0;
    }
    int j=0;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        while(a){
            string x;cin>>x;s+=x;
            j++;
        }
    }int cnt=0;
    for(int i=0;i<s.size();i++){
        if(i!=s.size()-i)cnt++;
    }
    cout<<cnt;
    return 0;
}
