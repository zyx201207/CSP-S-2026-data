#include<bits/stdc++.h>
#define int long long
#define inf 1e18
#define PII pair<int,int> 
using namespace std;
constexpr int N=2e6+5;
int c,t,n,k;
bool vis[N];
vector<int> g[N],choose;
int solve(int len,int k)
{
	return (len-k+1)/2+1;
}
void subtask1()
{
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++)	cin>>u>>v;
	int m=(n-1)/2;
	if(k==n)	cout<<"0\n";
	else if(k>=m)	cout<<"1\n";
	else if(m%2==0)
	{
		k-=k%2;
		m/=2,k/=2;
		cout<<(m-k+1)/2+1<<"\n";
	}
	else
	{
		cout<<max(solve(m/2,k/2),solve((m+1)/2,(k+1)/2));
	}
}
int popcnt(int x,int res=0)
{
	while(x)	res+=x%2,x/=2;
	return res;
}
void dfs(int u)
{
	vis[u]=1;
	for(int v:g[u])	if(!vis[v]&&binary_search(choose.begin(),choose.end(),v))	dfs(v);
}
bool check(int x)
{
	choose.clear();
	if(popcnt(x)!=k)	return 0;
	for(int i=1;i<=n;i++)	if((x>>i-1)&1)	choose.push_back(i);
	int cnt=0;
	for(int i=1;i<=n;i++)	vis[i]=0;
	for(int x:choose)	if(!vis[x])	cnt++,dfs(x);
	return cnt<=2;
}
int bfs(int u)
{
	for(int i=1;i<=n;i++)	vis[i]=0;
	queue<PII> q;
	q.push({0,u});
	while(q.size())
	{
		PII x=q.front();
		q.pop();
		int u=x.second,val=x.first;
		if(binary_search(choose.begin(),choose.end(),u))	return val;
		vis[u]=1;
		for(int v:g[u])	if(!vis[v])	q.push({val+1,v});
	}
}
int f(int x,int res=0)
{
	for(int i=1;i<=n;i++)	if(!binary_search(choose.begin(),choose.end(),i))	res=max(res,bfs(i));
	return res;
}
void subtask2()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)	g[i].clear();
	for(int i=1,u,v;i<n;i++)	cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
	int ans=inf;
	for(int i=1;i<(1<<n);i++)	if(check(i))	ans=min(ans,f(i));
	cout<<ans<<"\n";
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		if(c<=3)	subtask2();
		else if(c==13||c==14)	subtask1();
	}
	return 0;
}
/*
50min left
force+A	25pts
:(
ganjuezuihou50fenzhongshadouxiangbuchulaisqwlzhijiebailanle
eiwoshibushikeyixieyidianshenmineirongranhoubujiakonggekankanyoumeiyourennengpoyichulai
zheqizhenshenle
qishibenlaikeyidazhongwendedanshizhegeshenmijiqizhongwenshurufabuhaoshi
kaochangshanghaiyouyigexiaohaigebuhuijieyawenjianshizaishiguoyushenmile
kaoshizhiqiankandaozhouweiderenmeiyougaoerdeshenzhihaiyou8nianjide
zhenshityainiuleganjueziji8nianjideshihouC++shadoubuhuixianzaixiaohaizhenshitaiqiangle
oduilewohaideiqulinuxxiaceshiyixiawodedaimayoumeiyoushenmibugbunengzaixiangshangcimonisaiyiyangzhijiebaolingle
xiwangzyqzhecinengkailonglonglzjzhecinengjidechushihuabianliang
xiwangsuoyourenrp++++++zhuhkb4299
qishibenlaishixiangyongyingwenxiededanshiwodeyingwenshuipinghaishitaicileyouyinweizhongwenbuhaoshiyushijiuyongpinyinledanshihaibuxiangrangnimenzhemerongyijiukanchulaisuoyiwoyonglezhemeyigeshenmidefangshiyinnimenyishou
hahahahahahahahaha
total:100+100+48+25=273
buzhidaozhegemennengpaizayangganjueT1sbT2meiyounamenanyekenengshiwobiandenbleT3O(n^2)shijiandandedanshiO(n)wanquanmeisiluzhinengfangqileT4youyidianxiangfashihezhijingyouguandanshihouxuyoumeishaxiangfaleshenzhilianyouyubaolidezuofadoumeixiangchulaiyekenengshiwoyoudianleilelandexiang
gangcaiyoufalegeshenmixiaotiaobiquniangaojiganjuejinnianxianshangshoutinenghaoshizheyanghainengzaidianchuquwanshuanwganle
danshizhegetiaozhishiyonglaisaihoukanzijidaimadaxiaoshibushiyiyangdeshijiganjuemeiyourenheyongtu(((
bushizheqizhenshenlexianzaixianshangshoutihainenggaosudaimamingchengshibushizhengquede
zuigaoxiaodeshinagegongzhonghao30minzhihouhuigaosunishoushangqudedaimadaxiaoranhounijiudeizai20minzhineigandao411jifangzhaolaoshiranhoucainengjiancha
ganjue20minwanquanlaibujicongxiaowaihanhuizhegexuexiaoa50mingujidajiazaojiupaolule
zheqishenshenle
gangcailinuxxiabianyileerqiepaoleyibianzhihoudoumeiwentiwenjianmingchengkanleyimeiyouwentizhexiawenle
haiyou20minshishihoutijiaodaimaleganjuejiuzheyangbabuxiangzaixiezhemeyidatuoshihuohuonimenle
obuduihaimeikaiwangnawozhenghaobatijiedagaixiexiebadanshizheyangyetaishile
aifanzhengchishideshinimenjiujiuzheyangba
mndburangwoxuanzewenjianshangchunqisiwole
T1:
bufangqindingmouyigedaxiaoshimubiaodaxiaonamejiushikanzuiduonengbazuoshaoxiaoyutadebianchengta
zuihoudeyiyangdeshuijingyidingshiyigequjian
ranhoufaxianqujianzaikuozhandeyigezhihouzengjia/jianshaodedaijiashikeyiO(1)jisuanchulaide
nawomenjiuzhijieyongshuangzhizhensaoyibianxuliejike
shijianfuuzaduO(n)
T2:
guanchashujufanweifaxianditiexianluhenshaodanshizhantaihenduoerqiewomenzhiguanxinzouludelucheng
xianranyudaozheyangdeguanxizhijiejiantu
jiangxianluhezhantaifenbiedanchengdianranhoujiangmeigexianluxiangduiyingdezhantailianbian
danshizheyangdehuashijianfuzaduzhijiebaodiaolewomenxuyaoxiangxiangbiedefangfa
womenzaiciguanchafaxiandaijiajiushiditiekou->zhantai->mougexianlu->mougexianlu->zhantai->ditiekou
erqiemeigezhantaidexianluhenshaozhebianqishilewomenkeyimeijuzhantaiqianwangdeluxian
zheyangwomenjiuxiangdangyuzhidaoleshangmougeluxianshixuyaodedaijiajiexialaizhiyaonengchulichulaixianluzhijiandedaijiajike
danshizhijiepaofloydxianranzhijiebaozha
womenguanchafaxianliangtiaoxianlunenghuanchengdangqiejindangyigezhantaiyouzheliangtiaoxianlu
nawomenjiuduiyuduoyouzhantaijiangsuoyouxianluhuanchengsuoxudedaijiajianbianzhayangjiuyoulezhegezhantaihuanchengdedaijiazheyibushiO(md^2)de
ranhouwomenjiunengzhidaozhijingguoyigezhantaihuanchengdezuiduanjuli
cishidianshushiO(n)bianshushiO(n^2)zhijieyongncidijtaitanglesuoyiwomenyongfloydfuzadushiO(n^3)
zuihoutongjidaanjiushimeijujinzhankoushanglemnayigexianluyijichuzhankoucongnayigexianluxialaizaijiashangzhelianggexianludejulijikefuzadushiO(md^2)
zheyangjiuzuowanle
T3:
O(n^2)shijiandandezhixuyaobameigediannengdaodadedianlianbianranhoupaoyigezuiduanlujishuzhiyoucishuzhenghaodengyu2decaishihefade
Axingzhishijiandande
xianpanduanshifounengtiao>1gedaoyuruguozhinengtiao<=1genajiuzhijeishuchu0
fouzelingd=d/(x_2-x_1)zheyangjiubianchengleyixiakeyitiaoduoshaoge
ranhouwomenzaicishouwan/guanchayixiafaxianzhiyoujulidengyu2d-1delianggedaoyuzhijiancaihuiyougongxiansuoyizhijiesaoyiquanjike
fuzaduO(n)
zheyangjiuyou48ptsle
T4
meishashuode15fenbaolibushuole
Axingzhidehuahuatufaxianruguowomenbazhijinglinchulaidehuanamecezhidechangduzhiyou1erqiezuoyoushifenduichen
ranhoushouwanyixiajiunengfaxiandaandeguilvderanhouzhijiexiejike
danshizhiyouyigeyangliwoyebuquedingwodedaanduibuduixiwangnengdui
--------
zuoqianfangyougeshenmixiaohaixieguanzhutafeimiao
*/
