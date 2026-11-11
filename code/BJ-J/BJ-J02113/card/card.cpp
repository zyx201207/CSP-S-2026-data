#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1000009];
int fa[1000009];
int w[1000009];
int sz[1000009];
int an[1000009];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        w[a[i]]=max(w[a[i]],i);
        fa[i]=w[a[i]]+1;
    }
    for(int i=1;i<=n;i++){
        sz[i]++;
        sz[fa[i]]+=sz[i];
    }
    for(int i=1;i<=n;i++){
        an[a[i]]+=sz[i];
    }
    for(int i=1;i<=m;i++){
        cout<<an[i]<<" ";
    }
    cout<<endl;
    return 0;
}
/*
luogu uid:sbno333(!sbj)
416975
guan zhu wo !!!

This is an apple,I like apples,apples are good for our health.

sheng huo jiu xiang hai yang,zhi you yi zhi jian qiang de ren cai neng dao da bi an

wo chang chang zhui yi guo qu,sheng ming shun jian ding ge zai nao hai.
wo jiang bei hou de shi jian 1cai jian zhe die quan qu,rou nian cheng tian shang duo duo bai yun
yun duo zhi jian yi you fen bie,ji yun hou zhong er juan yun piao miao.
sheng ming li zhen han de chang jing lue guo wo de si xu bian yi sheng wu fa wang huai.
er geng wei pu tong ping chang de ji yi ze zai shi jian de chong shua xia zhi liu xia xie xu can hai.
zhui yi wan ru ru meng,tai guo qing chu ze wu fa yu yue zi ji de huan xiang,tai guo mo hu que you zhui ru xu wu.
wei you bo wu jian de shan shui,mian sha xia de nv zi,na qia dao hao chu de meng long,cai neng man zu wo dui mei de keqiu.
zhui yi zong zai bu jing yi jian jiang wo guo jin fan huang de zhi ye li,fen bie you chong ju de peng you,tui dao you chong jian de jian dao,
zhong zhong xian suo guo xie zhe wo yan yi ge ju ti de shi ke chu fa,yan shi jian de he ni liu er shang.
guo qu de ri zi wu fa chong lai,wo zhi shi yi ge guo ke,dan wo reng ran ke wang zai zhui yi zhi lv zhong liu xian xia shi jian,zai sui yue de meng long li zhu zu,
gan shou jin ke neng duo de tian mi,mei hao de shi guang ceng liu guo wo de shen ti,wo bian xin man yi zu.
guo qu yi jing ning gu,wo dai zhe hui yi xiang qian,ke shi you shi chang shu yu bao guan,hui yi ye zai gai bian ge zi de xing tai,zhe wei wo de zhui yi lv cheng dai lai le xie xu tiao zhan.
wo gai zai na li ting liu?wo wen wo zi ji.
------<<zhui yi>>

<<Jing wei>>
(mei ge,shen ti,qing bu zi jin)
shi xian zai wo suo you qi dai ai ai,suo you de ai ai,wei shen me bu ming bai ai ai~
shuo de hua wei shen me bu ji de ee,wei shen me bu ji de?
(yuan sheng ming zhan fang zai sheng kai)
ni yu wo xian tan xiang xin dian,hou bai pu lin shen,xian xia wen ji ye,chou du ji pian shi,ye ba!!!a~
zhi tian mo zai da hai?si wo de ai~,aaaa aaaaa aaaa,ta dao di wei shen me bu ji de ee?wei shen me bu ji de?
ta dao di yong shen me guan gai yong shen me lai ai?yong shen me fang shi,yong shen me qu dui dai ai~ ai ai ai~ai ai~
.....
chun hua shi qiu shi mo te,yan shi guo de,yan shen xiang hai,ta men zong shi guo ke,wo cai wo cai xiang zhou wei you ban lv sheng zhang,
wu fa fang qi,wu fa dui jiang.
ta shi ta de dui xiang,xiang gei wo yi ba zhang~,fan zheng wo mei quan tui,meng li dou shi jia xiang,wo zhi shi tai xiang yao fen ai~xiang yao fen ai,
wo zhi shi tai xiang bei hao hao dui dai ai ai~
dan shi ne wo xin zhong de yi yi?ai yi aui
nan dao wo shen shang tie zhe guo qu?!guo qu!
wo ming bai wo xin zhong de hai,tian man bu hui lai hui lai!
liu wen nong wo liu li bai zhan si de yi gui xiang xin yi hui.
yong wo men zhong guo hua lai shuo,shi ni de bu dui ai yi ai,la;
la la la la la la~la la la la la la~la la la la la la la......la la la la la la,la la la la la la,la la la la la!

<<Jing wei(DJ)>>
shi xian zai wo suo you qi dai ai ai,suo you de ai ai,wei shen me bu ming bai ai ai?
shuo de hua wei shen me bu ji de ee,wei shen me bu ji de?
si wo de ai ta dao di yong she me guan gai,yong shen me lai ai?
yong shen me fang shi,yong shen me qu dui dai ai,ai,a a a a a a a a a a a a a a a a~
suo wei you qiu er bu de?
ren xing yu he?
ke tian cang hai,cheng bai bu kan yi shuo!
ru ren jian guo ke,zong zhui zhe xu wu piao bo,
tang zhe lei he,che lun chen mo,
wan wu zhong gui xiang hai,he bi xian mu shi lai?
ye se sui feng yao bai,wo reng fei ben xiang hai?
wo zhi shi tai xiang yao fen ai?
wo zhi shi tai xiang bei hao hao dui dai~
ni yu wo xian tan yang xin dian,hou bai pu lin shen, xian xia wen ji ye,chong du ji pian shi ye ba~
zhi tian mo zai da hai.
shi xian zai wo suo you qi dai ai suo you de dai ai,wei shen me bu ming bai ai ai.
shuo de hua wei shen me bu ji de,ee,wei shen me bu ji de.
.......................................................................................................................
ni wen wo cun zai de yi yi ne?
tian man wo bei huan de zhi zhuo ne e?
wo ming bai wo xin zhong de hai,tian man bu hui lai hui lai!
ni yu wo xian tan yang xin dian,hou bai pu lin shen,xian xia wen ji ye,chou du ji pian shi ye ba~
zhi tian mo zai da hai.
jin ming zhong wan shi yi zi kong fu sheng fu si,yi yi cong rong!
po jiu ru hai zui dao tian di tou sheng cang qiong wan wu chang yong!
jin ming zhong wan shi yi zi kong fu sheng fu si,yi yi cong rong!
po jiu ru hai zui dao tian di tou sheng cang qiong wan wu chang yong!
......................................................
jin ming zhong wan shi yi zi kong fu sheng fu si,yi yi cong rong!
po jiu ru hai zui dao tian di tou sheng cang qiong wan wu chang yong!
jin ming zhong wan shi yi zi kong fu sheng fu si,yi yi cong rong!
po jiu ru hai zui dao tian di tou sheng cang qiong wan wu chang yong!
.~~~..................................................................
submit:
T1:travel
2026-10-31 08:41:32	530B
T2:string
2026-10-31 08:59:31	915B
T3:and
2026-10-31 09:04:52	637B
T4:card
2026-10-31 09:31:01	688B

I guess it's red yellow yellow green

1j:240

2j:120

3j:50

--- 11:11:11
I want to AK CSP-J.
I want to go to WC.
I want to AK NOIP.
I want to in APIO A.
I want to province team choose get 400+.
I want to get NOI A.
I want to get APIO Au.
I want to get 10 level.
I want to get NOI top 50 and into Chinese train team,get NOI Au.
I want to go to CTT.
I want to get bright life!!!
My whk is not good,help me!!!
I am grade 11,this is my last year,I maybe will AFO,but I don't want to AFO,I love OI!OI give me bright life!!!
I have DuiPai T2 T3 T4,please AK!!!
Please!!!
Fun fact:
Go to toilet need no more about 5 minute or became cheater.
password:Trick||Treat!
Teacher see I am playing game and let me close!
You ji:
zao shang lai dao kao chang,fa xian yi jiu mei nian CSP ji yi qing ling,yan su xun wen pang bian xiao hai zhu yi shi xiang.
kai shi le,dan shi ya suo bao dan wu le ji fen zhong.
kan T1 fa xian chun mo ni,xie le yi xia guo le.
kan T2 fa xian shi fen ma fan,xie le xiang dang yi hui caixie chu lai.
kai T3 fa xian shi ban zi,5 min xie wan.
kai T4 gen ben bu hui,zuo le yi wan nian fa xian di yi ge yuan su bu hui xiao chu,yu shi fa xian ke yi xie cheng zhuan yi de xing shi,xing cheng yi ke shu,bing qie tong se dian bu zai yi tiao zu xian lian,zhuan hua cheng zi shu da xiao qiu he,interesting!
AK le,kai shi gam
15 min limit gam,no!
xie dui pai,quan guo le,T1 nan yi dui pai,kan le kan mei ti bu fen fen,bei T1 kan xiao le.
xie yi wei bu ming,yu gu fen shu xian......
zong ti lai shuo 1h cai AK,zhe ge T4 zuo le 0.5h!!!
bu guo que shi you yi si.
*/
