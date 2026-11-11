#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL b(string s1,string s2){
    LL ans=0;
    int d=1;
    int f=min(s1.size(),s2.size());
    int i=0;
    while(i<f){
        if(s1[i]=='1'&&s2[i]=='1'){
            ans+=d;
        }
        d*=2;
        i++;
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    LL a[200005];
    string s[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int g=a[i];
        s[i]="";
        while(g){
            if(g%2){
                s[i]=s[i]+"1";
            }
            else{
                s[i]=s[i]+"0";
            }
            g/=2;
        }
    }
    if(m==1){
        LL ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    else if(m==2){
        LL ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,b(s[i],s[j]));
            }
        }
        cout<<ans;
        return 0;
    }
    else if(m==n){
        int f=1000000000;
        for(int i=1;i<=n;i++){
            if(s[i].size()<f){
                f=s[i].size();
            }
        }
        LL ans=0;
        int d=1;
        for(int i=0;i<f;i++){
            bool l=true;
            for(int j=1;j<=n;j++){
                if(s[j][i]!='1'){
                    l=false;
                }
            }
            if(l){
                ans+=d;
            }
            d*=2;
        }
        cout<<ans;
        return 0;
    }
    else if(m==n-1){
        LL cnt=0;
        for(int i=1;i<=n;i++){
            int f=1000000000;
            for(int j=1;j<=n;j++){
                if(j==i){
                    continue;
                }
                if(s[i].size()<f){
                    f=s[i].size();
                }
            }
            LL ans=0;
            int d=1;
            for(int k=0;k<f;k++){
                bool l=true;
                for(int j=1;j<=n;j++){
                    if(j==i){
                        continue;
                    }
                    if(s[j][k]!='1'){
                        l=false;
                    }
                }
                if(l){
                    ans+=d;
                }
                d*=2;
            }
            cnt=max(cnt,ans);
        }
        cout<<cnt;
        return 0;
    }
    cout<<a[n/2];
}