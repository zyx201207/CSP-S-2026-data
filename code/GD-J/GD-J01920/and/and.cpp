#include<bits/stdc++.h>
using namespace std;
int n,maxn=0,cnnt=1,m,maxx=0,cntt=0,pd[200005],xx=1,xxx=1,jsy=0;
bool bj=0;
long long x,z;
string a[200005],ans[200005];
int cnt[200005];
string f(long long kkk){
    string ans="";
    while(kkk>0){
        if(kkk%2==1) ans+="1";
        else ans+="0";
        kkk/=2;
    }
    return ans;
}
long long ff(string kkk){
    long long erm=1,ans=0;
    int ccc=0;
    while(ccc<int(kkk.size())){
        if(kkk[ccc]=='1') ans+=erm;
        erm*=2;
        ccc++;
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=35;i++) cnt[i]=0;
    for(int i=1;i<=n;i++){
        cin>>x;
        a[i]=f(x);
        cnt[int(a[i].size())]++;
        maxn=max(maxn,int(a[i].size()));
    }
    for(int i=maxn;i>=1;i--){
        jsy+=cnt[i];
        if(jsy>=m){
            maxx=i;
            break;
        }
    }
    if(maxx==0){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++) if(a[i].size()>=maxx) ans[cnnt++]=a[i];
    cnnt--;
    for(int i=maxx-1;i>0;i--){
        for(int j=1;j<=cnnt;j++){
            if(ans[j]!=""){
                if(ans[j][i]=='1') cntt++;
                else pd[xx++]=j;
            }
        }
        if(cntt>=m){
            for(int mm=xxx;mm<xx;mm++) ans[mm]="";
            xxx=xx-1;
            if(xxx+m==cnnt) break;
        }
        cntt=0;
    }
    for(int i=1;i<=cnnt;i++){
        if(ans[i]!=""){
            if(bj==0){
                z=ff(ans[i]);
                bj=1;
            }else z&=ff(ans[i]);
        }
    }
    cout<<z;
    return 0;
}
