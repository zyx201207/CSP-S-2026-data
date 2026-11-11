#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string to2(long long n){
    string s="";
    while(n!=0){
        s=s+char('0'+n%2);
        n/=2;
    }
    return s;
}
string ad(string a,string b){
    string s="";
    int mn=min(s.size(),b.size());
    for(int i=0;i<mn;i++){
        if(a[i]=='1'&&b[i]=='1')s+='1';
        else s+='0';
    }
}
long long to10(string s){
    long long sum=0;
    for(int i=0;i<s.size();i++){
        sum+=pow(2,i)*(s[i]-'0');
    }
    return sum;
}
int n,m;
long long a[N],sum,b,c,mx=INT_MIN;
string s[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(m=1){
        cout<<mx;
    }
    return 0;
}

