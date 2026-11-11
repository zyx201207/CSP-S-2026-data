/*
RP++
RP++
RP++
希望没有做能让我上迷惑行为大赏的事[合十][合十][合十]
还有这个“Trick||Treat!”是哪个大聪明想出来的密码啊
有个神人在那儿一直敲椅子(. ... . . .. . . )祝你上大赏[合十][合十][合十]
是不是觉得自己音乐天赋可高了敲得可好听了
我咋连暴力的英文都不知道……
朋友八百年前送的巧克力真好吃啊，就是咋还一股蜂蜜味
为啥每次比较正式的考试的时候就会想起来一堆很久以前听过的歌
“戏文说红颜总是薄命 书生几番多情 帝王身不由己 新词填旧曲 幕落又幕起 唯有那看客清醒” 
“戏文说相逢难逃别离 姻缘断情难续 殷勤X是假意 人心道不明 初听只当戏 再听已懂曲中意”
“Leave before you miss me  Do what you gotta to”
“'Cuz if you try to fix me  You'll be fixing you”
“我的悲伤 是水做的 是水做的”
“我预演过千次百次的重逢 你却始终站在梦里难 触碰”
“每当我拉着月亮 想大醉一场 它却照出记忆里你的模样”
“若我虔诚合十双手 唯愿你能得到拯救”
“你会翻过山 看到万丈青天 飞鸟正越过海面 你会迎着风放着胆唱着歌 把风景都看遍”
“你会翻过山 看到万里平原 天光正穿过云间 你会握着拳 赤着脚 流着汗 攀过千难万险”
“给你我的心做纪念 这份爱任何时刻你打开都新鲜 有我陪伴 多苦都变成甜 睁开眼就看见 永远”
“时光的河入海流 终于我们分头走 没有哪个港口 是永远的停留”
“我会牢牢记住你的脸 我会珍惜你给的思念 这些日子在我心中永远都不会抹去”
“唱出你的热情 伸出你双手 让我拥抱着你的梦 让我拥有你真心的面孔”
（这是毕业典礼四首）
（此处省略约2e9字）
T4咋就这点部分分
*/
#include<bits/stdc++.h>
using namespace std;
const int M=300000,N=500000;//3e5 5e5
int n,m;//5e5 3e5
int a[N+10],cnt[M+10],pos[M+10];//3e5 5e5 5e5
bool isA(){
    for(int i=1;i<n;i++)
        if(a[i]>a[i+1])
            return false;
    return true;
}
void A(){
    for(int i=1,j=1;i<=m;i++){
        while(a[j+1]==i)j++;
        cout<<j<<' ';
    }
}
void baoli(){
    for(int i=1;i<=n;i++){
        vector<int>v;//2e5
        for(int j=1;j<=m;j++)pos[j]=0;
        for(int j=i;j<=n;j++){
            int aj=a[j],&paj=pos[aj];//5e5
            if(paj==0){
                paj=j;
                v.push_back(j);
                // cout<<"\tadd "<<j<<'\n';
            }
            else
                for(int k=v.size()-1;k>=0&&v[k]!=paj;k--){
                    pos[a[v[k]]]=0;
                    v.pop_back();
                }
        }
        // cout<<i<<"  ";
        // for(int j:v)cout<<j<<' ';
        // cout<<'\n';
        for(int j:v)cnt[a[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
}
int main(){
    // freopen("card5.in","r",stdin);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(isA())A();
    else baoli();
    return 0;
}
// 1223334444 