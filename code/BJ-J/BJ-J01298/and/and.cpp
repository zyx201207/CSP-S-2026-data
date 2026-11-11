#include<bits/stdc++.h>
using namespace std;
struct shu{
    string s="";
};
shu sh[10000];
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n],c[n],d[n],maxn=0,cnt=0;
    memset(d,0,sizeof(d));
    for(int i=0;i<n;i++){
        cin>>a[i];
        while(a[i]!=0){
            sh[i].s=sh[i].s+char(a[i]%2+'0');
            a[i]=a[i]/2;
        }
        cnt=sh[i].s.size();
        c[i]=cnt;
    }
    for(int i=0;i<n;i++){
        if(c[i]>cnt)cnt=c[i];
    }
    int xx,cntt=0;
    for(int i=cnt-1;i>=0;i--){
        xx=pow(10,i);
        for(int j=0;j<n;j++){
            if(sh[i].s.size()>=i){
                if(sh[j].s[i])d[j]=1;
            }
        }
        for(int j=0;j<n;j++){
            if(d[j]==1)cntt++;
        }
        if(cntt>=m){
            break;
        }
        else{
            memset(d,0,sizeof(d));
            cntt=0;
        }
    }
    string ss;
    bool p=0;
    for(int i=0;i<n;i++){
        if(d[i]==1){
            m--;
            if(p==0){
                p=1;
                ss=sh[i].s;
            }
            else{
                for(int j=0;j<max(ss.size(),sh[i].s.size());j++){
                    if(sh[i].s[j]=='1')ss[j]='0';
                }
            }
        }

        if(m==0)break;
    }
    int ans=0;
    for(int i=0;i<ss.size();i++){
        ans=ans+pow(2,(ss.size()-i-1))*(ss[i]-'0');
    }
    cout<<ans;
}
