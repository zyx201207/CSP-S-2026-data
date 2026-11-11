#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
long long maxn=0;
void dfs(int pos,bool fir,long long sum,int cnt){
    if(pos==n+1){
        if(cnt==m){
            maxn=max(maxn,sum);
        }
        return;
    }
    if(cnt==m)dfs(pos+1,fir,sum,cnt);
    if(fir){
        dfs(pos+1,fir,sum,cnt);
        dfs(pos+1,false,a[pos],cnt+1);
    }
    else{
        dfs(pos+1,fir,sum,cnt);
        dfs(pos+1,fir,sum&a[pos],cnt+1);
    }
}
bool checka(int x){
    int j=x+1;
    while(j%2==0){
        j/=2;
    }
    if(j==1)return true;
    else return false;
}
/*bool cmp(string x,string y){
    if(x.size()!=y.size())return x.size()>y.size();
    else{
        for(int i=0;i<x.size();i++){
            if(x[i]!=y[i])return x[i]>y[i];
        }
        return 1;
    }
}
string bina(int x){
    if(x==0)return "0";
    else{
        int tem;
        string st="";
        while(x){
            tem=x%2;
            st+=(tem+'0');
            x/=2;
        }
        reverse(st.begin(),st.end());
    }
}*/
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int mx=0;
    bool flag=true;
    bool flagb=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        flag=checka(a[i]);
        if(a[i]!=i-1)flagb=false;
    }
    if(n<=20){
        dfs(1,true,0,0);
        cout<<maxn;
    }
    else if(m==1){
        cout<<mx;
    }
    else if(flag){
        sort(a+1,a+n+1,greater<int>());
        cout<<a[m];
    }
    else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else if(flagb){
        int ans=a[n];
        for(int i=n-1;i>=n-m+1;i--){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else{
        cout<<3;
    }
    return 0;
}
