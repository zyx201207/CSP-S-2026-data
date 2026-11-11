//ziSHUIJIN?!
//huleyigecaixiang,shishi.
//shijiansihudale.
//nule,zenmeyunxing 240.597s.
//wochangchangzhuiyiguoqvshengmingshunjiandinggezainaohaiwojiangbeihoudeshijiancaijianzhediequanqvrounianchengtianshangduoduobaiyunyunduozhijianyiyoufenbiejiyunhouzhongerjuanyunpiaomiaoshengmingzhongzhenhandechangjinlueguowodesixvbianyishengnanyiwanghuaiergenweipingchangputongdejiyizaishijiandechongshuaxiazhishengxiaxiexvcanhaizhuiyiwanrurumengtaiguoqingxizewufayvyuezijidehuanxiangtaiguomengdongqueyouxianruxvwuzhiyoubowujiandeshanshuimianshaxiadenvzinaqiadaohaochudemenglongcainengmanzuwoduimeidekeqiuzhuiyizongzaibujingyijianjiangwoguojinfanhuangdezhiyetuibaoyouchongjiandejiedaofenbieyouchongjvdepenyouzhongzhongxiansuoxiezhuzhewocongyigetedingdedidianchufayanshijiandeheniliuershangganshoujinkenengduodetianmimeihaodeshiguangcengliuguowodenaohaiwobianxinmanyizuguoqvyijingningguwodaizhehuiyixiangqianzhishishichangshuyubaoguanhuiyiyezaigaibianzhegezidexingtaizhegeiwodezhuiyizhilvdailaizhongzhongkunnanwogaizainalitingliuwowenwoziji
/*#include <bits/stdc++.h>
using ll=long long;
using namespace std;
ll n,m,a[900005],c[900005],s,now,nn,ss;//'c' is "cha"'s mean.
int main(){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);//wangle ios zenmeda,daimabuquanshenli!
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a+0,a+n);
    for(int i=0;i<n-1;i++){
        c[i]=a[i+1]-a[i];
    }
    for(int i=n-1;i>=0;i--){
        now=0;
        nn=0;
        ss=1;
        for(int j=i;j>=0;j--){
            nn+=c[j-1];
            now+=nn;
            //cout<<nn<<' '<<now<<' '<<ss<<' '<<c[j-1]<<'\n';
            if(now>m){
                break;
            }
            ss++;
        }
        s=max(s,ss);
    }
    cout<<s;
    return 0;
}*/
#include <bits/stdc++.h>
using ll=long long;
using namespace std;
ll n,m,a[900005],c[900005],s=1,now,nn,ss=1,l,r=0;//'c' is "cha"'s mean.
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);//wangle ios zenmeda,daimabuquanshenli!
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a+0,a+n);//nlogn
    //baixvdaozhibuyongchuli2333333333333333333333333zhileide
    for(int i=0;i<n-1;i++){
        c[i]=a[i+1]-a[i];
    }
    //chulideshiyimeigedianjieshudeduan
    //keyichangshixiugaiweihuadongchuangkouleixingde?
    for(int i=0;i<n-1;i++){//n2
        now+=(c[r]*(r-l+1));
        nn+=c[r];
        ss++;
       //cout<<now<<' '<<nn<<' '<<l<<' '<<r<<' '<<ss<<'\n';
        while(now>m){
            now-=nn;
            nn-=c[l];
            l++;
            ss--;
        }
//cout<<now<<' '<<nn<<' '<<l<<' '<<r<<' '<<ss<<'\n';
        s=max(s,ss);
        r++;
    }
    cout<<s;
    return 0;
}
//henhuang,sihuguobuqvdengchashulienagedian'a......................
//owocao,zuihoudeyige c youwenti!!!
//eixinghao.
