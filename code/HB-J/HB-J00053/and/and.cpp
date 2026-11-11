#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],b[10000005],l=1;
bool cmp(int a,int b){
    return a>b;
}
string change(int n){
    string s="";
    while(n){
        s+=(n%2+'0');
        n/=2;
    }
    return s;
}
int backto(string s){
    int wei=1,ans=0;
    for(int i=s.size()-1;i>=0;i--){
        ans+=(s[i]-'0')*wei;
        wei*=2;
    }
    return ans;
}
string and_and(string s,string s1){
    int l=s.size(),l1=s1.size(),cnt=0;
    string s_and="";
    for(int i=min(l,l1)-1;i>=0;i--){
        if(s[i]==s1[i]){
            s_and+="1";
            cnt++;
        }
        else s_and+="0";
    }
    return s_and;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int j=1;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            string s3=and_and(change(a[i]),change(a[i+j]));
            b[i]=backto(s3);
        }
    }
    sort(b,b+10000006,cmp);
    cout<<b[0];
    return 0;
}
