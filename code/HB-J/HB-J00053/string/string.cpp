#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
string s="";
int a[200005];
string hw(string s){
    string ss="";
    long long len=s.size();
    for(int i=len-1;i>=0;i--)ss+=s[i];
    return ss;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s1;
        cin>>a[i];
        cin>>s1;
        for(long long j=1;j<=a[i];++j){
            s+=s1;
        }
    }
    if(hw(s)==s){
       cout<<0;
       return 0;
    }
    int l=s.size();
    string s_front,s_back;
    for(long long i=0;i<l/2;i++) s_front+=s[i];
    if(l%2==0){
        for(long long i=l/2;i<l;i++) s_back+=s[i];
    }
    else{
        for(long long i=l/2+1;i<=l;i++) s_back+=s[i];
    }

    long long l_fb=s_front.size();
    s_back=hw(s_back);

    for(long long i=0;i<l_fb;i++){
        if(s_front[i]!=s_back[i])cnt++;
    }
    cout<<cnt;
    return 0;
}
