#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans;
long long f(long long a,long long b){
    //短除法
    string ta="";
    while(a!=0){
        ta=to_string(a%2)+ta;
        a=a/2;
    }
    string tb="";
    while(b!=0){
        tb=to_string(b%2)+tb;
        b=b/2;
    }
    //按为与
    string s="";
    for(int i=0;i<max(ta.size(),tb.size());i++){
        if(ta[i]=='1'&&tb[i]=='1'){
            s=s+'1';
        }else{
            s=s+'0';
        }
    }
    //变回十进制
    long long h=0,j=0;
    for(int i=s.size()-1;i>=0;i--){
        long long t=1;
        for(int k=1;k<=j;k++){
            t=t*2;
        }
        h=h+(s[i]-'0')*t;
        j++;
    }
    return h;
}
void dfs(long long x,long long cnt,long long he){
    if(x==n){
        if(cnt==m){
            ans=max(ans,he);
        }
        return;
    }
    dfs(x+1,cnt+1,f(he,a[x]));
    dfs(x+1,cnt,he);
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long mx=0,y=1;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        y=f(y,a[i]);
    }
    if(m==1){
        cout<<mx;
        return 0;
    }
    if(m==n){
        cout<<y;
        return 0;
    }
    dfs(0,0,0);
    cout<<ans;
    return 0;
}
