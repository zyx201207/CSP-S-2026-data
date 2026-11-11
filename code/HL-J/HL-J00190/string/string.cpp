#include <bits/stdc++.h>
using namespace std;
int ans=0;
string s1,s2;
string l1,l2,r1,r2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        string b;
        cin>>a>>b;
        for(int j=0;j<a;j++){
            s1+=b;
        }
    }
    s2=s1;
    reverse(s2.begin(),s2.end());
    l1=s1;
    r1=s1;
    l2=s2;
    r2=s2;
    if(s1.size()%2==0){
        l1.erase(s1.size()/2);
        r1.erase(0,s1.size()/2);
        l2.erase(s2.size()/2);
        r2.erase(0,s2.size()/2);
    }else{
        l1.erase(s1.size()/2);
        r1.erase(0,s1.size()/2+1);
        l2.erase(s2.size()/2);
        r2.erase(0,s2.size()/2+1);
    }
    for(int i=0;i<l1.size();i+=2){
        if(l1[i]!=l2[i]){
            ans++;
        }
    }

    cout<<ans;
    return 0;

}
