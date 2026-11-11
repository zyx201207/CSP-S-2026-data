#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v[32];
int f[200010][32];
int a[200010];
string s[200010];
int len[200010];
int prans[32];
string solve(int k){
    string ans="";
    while(k!=0){
        ans=ans+char(k%2);
        k/=2;
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    int len1=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=solve(a[i]);
        len1=max(len1,int(s[i].size()));
        len[i]=s[i].size();
    }
    for(int i=1;i<=n;i++){
        int h=0;
        for(int j=len1;h<len[i];j--,h++)
            f[i][j]=s[i][h];
    }
    for(int i=1;i<=n;i++) v[0].push_back(i);
    for(int i=1;i<=len1;i++){
        int cnt=0;
        for(auto u:v[i-1]){
            if(f[u][i]==1)
                cnt++;
        }
        if(cnt<m){
            for(auto u:v[i-1])
                v[i].push_back(u);
        }else{
            for(auto u:v[i-1])
                if(f[u][i]==1)
                    v[i].push_back(u);
            prans[i]=1;
        }
    }
    int type=1;
    int ans=0;
    for(int i=len1;i>=1;i--){
        ans+=prans[i]*type;
        type=type*2;
    }
    printf("%d",ans);
}
