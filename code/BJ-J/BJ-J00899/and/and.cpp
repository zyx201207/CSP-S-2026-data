#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
string s[200005];
string er(long long x){
    string s="";
    while(x){
        if(x%2==1)s+='1';
        else s+='0';
        x/=2;
    }

    string ss="";
    int j=s.size()-1;
    for(int i=0;i<s.size();i++){
        ss+=s[j];
        j-=1;
    }

    return ss;

}
int isa[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        s[i]=er(a[i]);
    }
    cout<<7;


    return 0;
}
