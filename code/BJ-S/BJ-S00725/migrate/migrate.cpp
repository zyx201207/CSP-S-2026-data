/*
那年风吹过海棠 你的目光
热切能与天光相当 轻唤我回神一望
眼前少年 携段春光
未曾想 人世变幻有多无常
那年有漫天飞霜 你的手掌
赠我心头一片温烫 降临第一场春光
前世今生 如何能忘
未曾想 这情一字多么长
后来蚀骨香 悄开放 从此天各一方
渐行渐远渐一半 心事隐秘成过往
一枕黄粱梦太长 仰看此月光
照天地苍茫 却有花影成双
爱恨此消彼长 停步回望 我陪你同往
念想从未消亡 踏断红尘 不肯相忘
飞上九天落千丈 为你闯一趟
若你独留远方 谁来与我相望
三千石阶太冰凉 他曾铺上
一路死生余下悲伤 缘分错落如参商
仓皇思量 爱意私藏
不愿想 这情一字有多荒唐
解语海棠花 未消散 寄我情深一往
若赠魂灵我胸膛 年华暗换莫惆怅
你的模样刻心上 恰似此月光
照天地苍茫 却有花影成双
爱恨此消彼长 停步回望 我陪你同往
念想从未消亡 踏断红尘 不肯相忘
飞上九天落千丈 为你闯一趟
若你独留远方 谁来与我相望
*/
#include<bits/stdc++.h>
using namespace std;
constexpr int N=2000006;
int id,T,n,L[N],R[N];
long long d,ans,a[N];

int to[N];
long long f[N];

int cnt[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>id>>T;
    while(T--){
        cin>>n>>d,ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        {
            queue<int>q;
            for(int i=1;i<=n;i++){
                while(!q.empty()&&a[i]-a[q.front()]>d)R[q.front()]=i-1,q.pop();
                q.push(i);
            }
            while(!q.empty())R[q.front()]=n,q.pop();
            for(int i=n;i;i--){
                while(!q.empty()&&a[q.front()]-a[i]>d)L[q.front()]=i+1,q.pop();
                q.push(i);
            }
            while(!q.empty())L[q.front()]=1,q.pop();
        }
        if(id==13||id==14){
            fill(cnt,cnt+1+n,0);
            for(int i=n,j=n;i;i--){
                while(j>R[i])cnt[L[j--]]++;
                ans+=cnt[R[i]-1];
            }
        }
        else{
            for(int i=n;i;i--){
                for(int j=i;;j=L[j]){
                    for(int k=L[j];k<j;k++)to[k]=j;
                    if(j==L[j])break;
                }
                for(int j=i;j<=n;j++)f[j]=0;
                for(int j=i;j-->L[i];)f[j]=f[j+1]+1;
                for(int j=L[i];--j;)f[j]=f[j+1]+f[to[j]]-f[R[j]+1];
                for(int j=i;--j;){
                    if(f[j]-f[j+1]==2)ans++;
                    if(j==L[j])break;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
单调队列求出管辖范围,若未超过终点则一定飞得最远.由此可以求出两点之间最短距离.
最短路恰有两条意味着什么?

好像?R[i] \in {L[j]+1,L[L[j]+1],L[L[j]]+1,L[L[L[j]+1]],L[L[L[j]]+1],L[L[L[j]]]+1,...}
滚木套滚木还在追我!
*/