#include <bits/stdc++.h>
using namespace std;
const long long N=2*1e5+2;
long long n,m,a[N],temp=2147483647,mn=-1,len=0,da=0;
string s[N],daan="";
bool cmp(long long x,long long y){
    return x>y;
}
string b0(string x){
    if(x.length()==len){
        return x;
    }else{
        string temps="";
        for(long long i=x.length();i<len;i++){
            temps+="0";
        }x=temps+x;
    }
    return x;
}
string aaa(long long x){
    if(x==1){
        return "1";
    }stack <char> s;
    while(x>0){
        char temp=(x%2)+'0';
        x/=2;
        s.push(temp);
    }string ss="";
    while(!s.empty()){
        ss+=s.top();
        s.pop();
    }
    return ss;
}
bool cmpp(string x,string y){
    for(long long i=0;i<len;i++){
        if(x[i]!=y[i]){
            return x[i]>y[i];
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(m==n){
            temp&=a[i];
        }string ttemp=aaa(a[i]);
        long long lenl=ttemp.length();
        len=max(len,lenl);
        s[i]=ttemp;
    }if(m==1){
        stable_sort(a+1,a+n+1,cmp);
        cout<<a[1];
        return 0;
    }if(m==n){
        cout<<temp;
        return 0;
    }if(m==2){
        for(long long i=1;i<n;i++){
            for(long long j=i+1;j<=n;j++){
                mn=max(a[i]&a[j],mn);
            }
        }cout<<mn;
        return 0;
    }for(long long i=1;i<=n;i++){
        s[i]=b0(s[i]);
    }sort(s+1,s+n+1,cmpp);
    daan=s[1];
    for(long long i=2;i<=m;i++){
        for(long long j=0;j<len;j++){
            if((daan)[j]=='1'&&(s[i])[j]=='1'){
                daan[j]='1';
            }else{
                daan[j]='0';
            }
        }
    }reverse(daan.begin(),daan.end());
    for(long long i=0;i<daan.length();i++){
        da+=(daan[i]-'0')*pow(2,i);
    }cout<<da;
    return 0;
}
