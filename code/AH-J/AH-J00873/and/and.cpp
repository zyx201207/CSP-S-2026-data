#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[200010],d[200010][40];
string s[200010];
bool f[200010];
string trans(LL n){
    string ss;
    while(n){
        ss+=(n%2+'0');
        n/=2;
    }
    reverse(ss.begin(),ss.end());
    while(ss.size()<30) ss='0'+ss;
    return ss;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    LL n,maxn=0,m;
    cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            s[i]=trans(a[i]);
            for(int j=0;j<s[i].size();j++){
                d[i][j+1]=s[i][j]-'0';
            }
        }
        bool b=0;
        for(int j=30;j>=1;j--){
            LL ans=0,p;
            bool t=0;
            for(int i=1;i<=n;i++){
                if(f[i]==1) continue;
                if(d[i][j]==1){
                    ans++;
                    if(t==0){
                        t=1;
                        p=a[i];
                    }
                    p=(p&a[i]);
                }
            }
            if(ans==m){
                cout<<p;
                b=1;
                break;
            }
            else if(ans<m) continue;
            else{
                for(int i=1;i<=n;i++){
                    if(f[i]==1) continue;
                    if(d[i][j]==0){
                        f[i]=1;
                    }
                }
            }
        }
        LL q=1,cnt=0;
        bool l=0;
        if(b==0){
            for(int i=1;i<=n;i++){
                if(f[i]==1) continue;
                cnt++;
                if(cnt>m) break;
                 if(l==0){
                        l=1;
                        q=a[i];
                    }
                    q=(q&a[i]);

            }
            cout<<q;
        }
    return 0;
}

