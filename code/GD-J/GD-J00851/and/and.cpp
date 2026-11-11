#include<bits/stdc++.h>
using namespace std;
int n,m,maxx,ans;
bool flag=0;
int a[1919810];//从2^0到2^30
vector<int> sum[32];
bitset<1919810> c;
void dfs(int las,vector<int> b,int ans1){
    for(int i=las;i>=0;i--){
        int cur=0;
        vector<int> c;
        for(int k:b){
            int cnt=pow(2,i);
            if(k&cnt)
                cur++,
                c.push_back(k);
        }
        if(cur>=m){
            dfs(i-1,c,ans1+pow(2,i));
            break;
        }
    }ans=max(ans,ans1);
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int aa=a[i];
        queue<int> cnt;
        while(a[i]){
            if(a[i]%2){
                cnt.push(1);
            }else{
                cnt.push(0);
            }
            a[i]/=2;
        }int len=cnt.size();
        for(int j=0;j<len;j++){
            if(cnt.front()==1)
                sum[j].push_back(aa);
            cnt.pop();
        }
    }
    for(int i=29;i>=0;i--){
        if(sum[i].size()>=m){
            dfs(i-1,sum[i],pow(2,i));
            break;
        }
    }
    cout<<ans;
}
/*
洛谷关注uid1063830谢谢喵

10：49分开始做T3
11：40分，决定暴力
11：50分，T3乱搞过了？？？

预计100+100+100+30！！！
*/