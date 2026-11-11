#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m;
long long ans,d;
const int N=2e5+7;
long long a[N],b[N];
long long f(long long x,int y){
    string s1,s2,s3;
    long long c=0;
    while(x>0){
        s1+=(x%2)+'0';
        x/=2;
    }
    while(y>0){
        s2+=(y%2)+'0';
        y/=2;
    }
    for(int i=0,j=0;i<s1.size(),j<s2.size();i++,j++){
        if(s1[i]=='1'&&s2[j]=='1') s3+='1';
        else s3+='0';
    }
    for(int i=s3.size()-1;i>=0;i--){
        c+=(s3[i]-'0')*pow(2,i);
    }
    return c;
}
void dfs(int start,int cnt,long long sum){
    if(cnt==m){
        ans=max(ans,sum);
        return;
    }
    if(n-start+1<m-cnt) return;
    for(int i=start;i<min(n,n-(m-cnt)+1);i++){
        dfs(start+1,cnt+1,f(sum,a[i]));
        dfs(start+1,cnt,sum);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
    }
    else if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                d=f(a[i],a[j]);
                ans=max(ans,d);
            }
        }
    }
    else if(m==3){
        for(int i=1;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<=n;k++){
                    d=f(a[i],a[j]);
                    d=f(d,a[k]);
                    ans=max(ans,d);
                }

            }
        }
    }
    else dfs(1,0,pow(2,20)-1);
    cout<<ans;
    return 0;
}
