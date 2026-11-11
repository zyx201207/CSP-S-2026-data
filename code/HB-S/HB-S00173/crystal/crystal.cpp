#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005];
ll c[500005];
ll n,m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++)
    {
        c[i]=a[i+1]-a[i];
    }
    ll l=1,r=0,siz=0,cnt=0,ans=0,lencn=0;
    while(r<n-1)
    {
        r++;
        siz++;
        cnt+=siz*c[r];
        //cout<<l<<' '<<r<<' '<<siz<<' '<<cnt<<'\n';
        lencn+=c[r];
        if(cnt<=m)
        {
            ans=max(ans,siz);
        }
        else{
            while(cnt>m)
            {
                siz--;
                cnt-=lencn;
                lencn-=c[l];
                l++;
            }
        }
    }
    cout<<ans+1;
    return 0;
}
/*
1 2 4 8 9
1 2 4 1
1 5
  2


Happy Halloween!
I'm Kremlin897!(luogu=1046158)
I don't know why my number=CSP00173
14:59 AC T1!✅
very well
this morning i ate two shilijia(my english is yihetuan)
🗿🗿🗿🗿🗿🗿🗿🗿🗿🗿

bur T2-4 all the tulun QAQ

15:19 T2 hao xiang you yi dian xiang fa ke yi da bao li

Oct 31 == Dec 25?!
Halloween == Xmas?!
≌≌≌

ban shang yun dong hui shen ren gao zi
815 ban zui zhong bing qi zui qiang wu yan zu CJJ gang cai zai cao chang shang san bu yi bu xiao xin da po le xiao yun hui ji lu!
ta chuan zhe tuo xie cong qi pao xian fei ben er chu

can you play honkai:star rail?
UID:134183549

16:17 T2+32

ji cheng tian si ye you                    📖 🏯 🌔 👣
yuan feng liu nian shi yue shi er ri ye    yuanfeng 6th year Oct 12th 🌔
jie yi yu shui                             want to 🛏
yue se ru hu                               🌔 go to 🏠
xing ran qi xing                           get up happily🤪
nian wu yu wei le zhe                      there is no friends play with me
sui zhi cheng tian si xun zhang huai ming  go to the 🏯 to find 🙋
huai ming yi wei qing                      🙋 no 🛌 too
xiang yu bu yu zhong ting                  👬 👣 🏯
ting xia ru ji shui kong ming              under the 🏯 is 🌔 and water
shui zhong zao xing jiao heng              many plants in the water
gai zhu bai ying ye                        perhaps 🌲🀤🌲🀤🌲🀤
he ye wu yue                               where have not 🌔
he chu wu zhu bai                          where have not 🌲🀤
dan shao xian ren ru wu liang ren zhe er   there have not 👬

17:14 T3+8

17:57 T4+10

yugu:100+32+8+10=150
dan yuan bie gua fen


♿♿♿gunmu gunmu gunmu♿♿♿

bye bye zhun bei bu jiao
suan le bie shui le

kan dao zhe li le neng gei ge guan zhu ma
*/
