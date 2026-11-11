#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    string s;
    int il=1,val;
}g[200010];
int n,m,y[200010],sum,f=1;
string tur(int k){
    string res="";
    int l=0;
    while(k)res=res+(char)((k%2)+'0'),k/=2,l++;
    for(int i=l;i<32;i++)res=res+'0';
    for(int i=0;i<16;i++)swap(res[i],res[31-i]);
    return res;
}
bool cmp(node a,node b){return a.val>b.val;}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m,sum=n;
    for(int i=1;i<=n;i++)cin>>g[i].val,g[i].s=tur(g[i].val);
    sort(g+1,g+n+1,cmp);
    for(int i=0;i<=31;i++){
        int cnt=0;
        memset(y,0,sizeof y);
        for(int j=1;j<=n;j++)if(g[j].il==0||g[j].s[i]=='0')y[++cnt]=j;
        if(n-cnt<m)continue;
        if(n-cnt>=m&&f){
            for(int j=cnt;j>=1;j--){
                if(sum<=m){f=0;break;}
                else{
                    if(g[y[j]].il==0)continue;
                    else g[y[j]].il=0,sum--;
                }
            }
        }
    }
    int ans,cnt=0,f1=1;
    for(int i=1;i<=n;i++){
        if(cnt>=m)break;
        else{
            if(g[i].il){
                if(f1){ans=g[i].val,f1=0,cnt++;continue;}
                else cnt++,ans=ans&g[i].val;
            }
            else continue;
        }
    }
    if(cnt<m)cout<<0;
    else cout<<ans;
    return 0;
}