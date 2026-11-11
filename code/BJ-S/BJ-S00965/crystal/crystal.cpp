#include<bits/stdc++.h>
using namespace std;
#define int long long
struct aaa{
    long long s,c;
}a[500005];
long long n,m,l=2147483647,r=-2147483647,maxx=-2147483647;
bool cmp(aaa x,aaa y){
    return x.c<y.c;
}
int check(int x){
    //cout<<x<<endl;
    for(int i=0;i<n;i++){
        if(a[i].s<=x){
            a[i].c=x-a[i].s;
        }else{
            a[i].c=1000000000005;
        }
    }
    for(int i=0;i<n;i++){
        //cout<<i<<' '<<a[i].s<<' '<<a[i].c<<endl;
    }
    sort(a,a+n,cmp);
    int js=0,lsn=m;
    for(int i=0;i<n;i++){
        if(lsn-a[i].c>=0){
            js++;
            lsn-=a[i].c;
            //cout<<js<<' '<<lsn<<endl;
        }else{
            break;
        }
    }
    //cout<<js<<endl<<endl;
    return js;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i].s;
        l=min(a[i].s,l);
        r=max(a[i].s,r);
    }
    for(int i=l;i<r;i++){
        maxx=max(maxx,check(i));
    }
    cout<<maxx;
    return 0;
}
//qinglisinianchun,tengzijingzheshoubalingjun,yuemingnian,zhengtongrenhe,baifeijuxing,naichongxiuyueyanglou,zengqijiuzhi,ketangxianjinrenshifuyuqishang,zhuyuzuowenyijizhi.
//yuguanfubalingshengzhuang,zaidongtingyihu,xianyuanshan,tunchangjiang,haohaoshangshang,hengwujiya,ranzebeitongwuxia,nanjixiaoxiang,qiankesaoren,duohuiyuci,lanwuzhiqing,dewuyihu?
//ruofuyinyufeifei,lianyuebukai,yinfengnuhao,zhuolangpaikong,rixingyinyao,shanyueqianxing,shanglubbuxing,qiangqingjicui,dengsilouye,zeyouquguohuaixiang,youchanweiji,manmuxiaoran,ganjierbeizheyi.
//zhiruochunhejingming,bolanbujing,shangxiatianguang,yibiwanqing,shaouxiangji,jinlinyouyong,anzhitinglan,yuyuqingqingmdengsilouye,zeyouxinkuangshenyi,bajiulinfeng,qixiyangyangzheyi.
//yuchangqiugurenrenzhixin,huoyierzhezhiwei,hezai?buyiwuxi,buyijibei.jumiaotangzhigaozeyouqimin,chujianghuzhyuanzeyouqijun,shijinyiyou,tuiyiyou,ranzeheshierleye?qibiyue:"xiantianxiazhiyoueryou,houtianxiazhileerle"hu!yi!weisiren,wusheiyugui?shiliunianjiuyueshiwuri.
