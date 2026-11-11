#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string memo[1000][1000];
#define int unsigned long long
int n,m;

int a[N];
string sum[N];
int ans=0;
string twos(int x){
    string s="";
    while(x){
        char c;
        c=x%2+'0';
        s+=c;
        x/=2;
    }
    return s;
}
string ands(string x,string y){
    string s="";
    long long k1=x.size()-1,k2=y.size()-1;
    for(;;){
        if(x[k1]=='1'&&y[k2]=='1'){
            s+="1";
        }else{
            s+='0';
        }
        k1--;
        k2--;
        if(k1<0||k2<0){
            break;
        }
    }
    string s1="";
    for(long long i=s.size()-1;i>=0;i--){
        s1+=s[i];
    }
    return s1;
}
int tens(string s){
    int k=0;
    for(int i=0;i<s.size();i++){
        k+=(s[s.size()-i-1]-'0')*pow(2,s.size()-1-i);
    }
    return k;
}
void dfs(string onnow,int step,int sums){
    if(sums==m+1){
        //cout<<onnow<<":"<<tens(onnow)<<" ";
        ans=max(tens(onnow),ans);
        return ;
    }
    if(step>n){
        return ;
    }
    for(int i=step;i<=n;i++){
        dfs(ands(sum[step],sum[i]),i+1,sums+1);
        
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    string s="";
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=twos(a[i]);
    }
    dfs(sum[1],(int)0,(int)0);
    cout<<ans;
}
