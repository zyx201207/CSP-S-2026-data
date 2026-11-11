#include<bits/stdc++.h>
//#define int long long
using namespace std;
#define pii pair<int,int>
#define endl '\n'
#define pb push_back
int a[500010];
int vis[5010];
int ans[500010];
int b[5010],pos=0;
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int flag=1;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            flag=0;
            break;
        }
    }
    if(flag==1){
        int ans=1;
        for(int i=1;i<n;i++){
            if(a[i-1]!=a[i]){
                cout<<ans<<' ';

            }
            ans++;
        }
        cout<<ans<<' ';
        return;
    }
    if(n<=5000){
        for(int i=0;i<n;i++){
                for(int i=1;i<=m;i++)vis[i]=1e9;
            for(int j=i;j<n;j++){
                if(vis[a[j]]!=1e9){
                    while(b[pos]!=a[j]&&pos>0){
                        if(vis[b[pos-1]]>=vis[a[j]]){
                            vis[b[pos-1]]=1e9;
                            //cout<<11919<<' ';
                        }
                        pos--;
                        //cout<<114514<<' ';
                    }
                    //cout<<endl;
                }
                b[pos++]=a[j];
                vis[a[j]]=min(vis[a[j]],j);
            }

            for(int i=0;i<pos;i++){
                    //cout<<b[i]<<' ';
                ans[b[i]]++;
            }
            //cout<<endl;
            pos=0;
        }
        for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return ;
    }
    for(int i=0;i<n-1;i++){
        ans[a[i]]++;
    }
    ans[a[n-1]]=n;
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }

}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    //freopen("and3.in","r",stdin);
    //freopen("and.out","w",stdout);
    int t=1;
    //cin>>t;
    while(t--)solve();
}
/*
我是不是见过你，那时你还是个T1
9:40洗了个脸舒服炸了
模拟题？
code code forces is wairy good
31
1
21
1
31
21
31
1
21
1
不会做啊！
1112233334
1234
1234
1234
234
234
34
34
34
34
4
10：15做完T3回来了，目前300pts预测，希望不要出茬子
我会做T3说明今年的分数线可能是1=402pts,2=401pts,3=400pts;
哈哈
我爱你 coin coding function

今年的题预测红红红黑
T4特殊性质A:一直炸直到+
特殊性质B看不懂
每个题都会有这种迷惑的特殊性质B
1111334
134
134
134
134
34
34
4


我真不行了这T4太难了推了15min没搞明白题
从后往前看每个数有没有被炸会不会好一点
最后一个肯定是n
倒数第二个。。。
怎么做啊！！！！🤓☝
😢

欸
如果一个数在一局里是第一个那么这玩意一定不会死
哦也
如果当第一的没有能力炸第二个那么第二个也活了
哦也
能不能先模拟一次爆炸然后根据这次推断之后所有局面？
可以倒着模拟吗？🤓☝🤓☝🤓☝
好像不太行，会提前把右端点吃了

woc原来是12:00结束吗我以为12:30
快想啊
终于把烂的14的做法整出来了

第二版新鲜出炉
我真不会写了
😺🐺🌶🐶🏠🔛🌒🌑🎹🥁☯🕐🕑🕒🍀🕔🕕🕖🕗🕘🥌☝🕦🕛📨⭕✖🏎🐮💠👨‍✈🕊👮🥇⛳🈴🐧🤓🏇
🈴🐧🤓☝
🦐🍤
预测今年分数 100+100+100+114514(实际应该是100+100+100+(40or52or16))大概能过吧
*/
