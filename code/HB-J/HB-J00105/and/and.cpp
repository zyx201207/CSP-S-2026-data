#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,i,j,s=0;
int a[211111];
int w(int i,int s,int x){
    if(i>n)return -1;
    if(x>m)return s;
    int ss;
    for(;i<=n;i++){
        ss=s&a[i];
        ss=w(i+1,ss,x+1);
        s=max(ss,s);
    }
    return s;
}
//vector<int>q[33];
//map<int,int>mp;
//int sum[33];
void solve(){
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
//        for(j=0;j<=30;j++)
//            if(a[i]&(1<<j)>0)
//                q[j].push_back(i);
    }
/*    for(j=30;j>=0;j--){
        if(q[j].size()>=m)
            break;
    }
    s=1;
    if(j==-1){
        cout<<0;
        return;
    }
    if(j==0){
        cout<<1;
        return;
    }
    sum[j]=1;
    for(i=0;i<q[j].size();i++)
        mp[q[j][i]]++;
    for(j--;j>=0;j--){
        for(i=0;i<q[j].size();i++)
            mp[q[j][i]]++;
        int ss=0;
        for(auto it:mp){
            if(it.second>s)
                ss++;
        }
        if(ss<m){//bu xing!
            for(i=0;i<q[j].size();i++)
                mp[q[j][i]]--;
        }
        else{
            s++;
            sum[j]=1;
        }
    }
    s=0;
    for(j=0;j<=30;j++){
        if(sum[j])
            s+=(1<<j);
    }
    cout<<s;*/
    if(n==m){
        for(i=1;i<=n;i++)
            s&=a[i];
        cout<<s;
        return;
    }
    cout<<w(1,0,0);
}
signed main(){
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  int t=1;
  //cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
///continued from T2's end
///01:50~02:05 check(T2) used("ls","cd","diff","rm") xia xiang de fang fa jv ran quan dui <(0o0)>
///02:27~02:28 went to WC
///02:40 xiang dao le T3 de yi ge jue miao de jie fa
///02:05~03:05 do(T3)
///03:05~03:10 !check(T3) QAQ
///03:24       ...zao zhi dao jiu zuo T4 de
//Goodbye,my first CSP-J.
//by luogu:huan9178
//   QQ:318657186
