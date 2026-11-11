#include<bits/stdc++.h>
using namespace std;
const int N=500005;
vector<long long> pos;
long long ans,a[N];
int num[N];
//num存储下标，是计数的临时数组 pos存储这个下表对应的数字
//an是映射完的数组 与num同理  是不重复的
//an理论上与pos完全相同
long long n=0,m=0;
int cnt=1;
int cal(){
    //@cal 返回众数的pos
    //众数出现的位置
    int maxpos=0,maxnum=0;
    int tN=0,lstN=a[1];
    //pos[++cnt]=a[1],num[cnt]++;
    pos.push_back(0);// 占位
    pos.push_back(a[1]);
    num[cnt]=1;
    for(int i=2;i<=n;i++){
        tN=a[i];
        if(tN!=lstN){
            //pos[++cnt]=a[i];
            cnt++;
            pos.push_back(a[i]);
            //an.push_back(a[i]);
        }
        //num[cnt]++;
        num[cnt]++;
        //an[cnt]=a[i];
        if(maxnum<num[cnt]){
            maxnum=num[cnt];
            maxpos=cnt;//后续计算直接用pos
        }
        lstN=tN;
    }
    return maxpos;
}
void print(){
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<"\n";
}
int func(int k){
    //@func:接受 cnt 返回中位数的 pos
    // int tk=k/2;
    return k/2+1;
    // if(2*tk!=k){
    //     //基数 直接采纳+tk+1
    //     return tk+1;
    // }
    // else{
    //     return tk;
    // }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    //print();
    //cout<<"-----------\n";
    int tpos=0;
    tpos=cal();
    if(tpos==2)tpos=func(cnt);
    int tmpm=m;
    ans=num[tpos];
    for(int i=tpos-1;i>=1;i--){
        int klr=(pos[tpos]-pos[i]);
        int ss=abs(klr*num[i]);
        if(tmpm>=ss){
            ans+=num[i];
            tmpm-=ss;
        }
        else{
            int s2=tmpm/klr;
            tmpm-=s2*klr;
            ans+=s2;
        }
        if(tmpm<=0)break;
    }
    if(tmpm<=0){
        cout<<ans<<"\n";
    }
    else{
        //一次次向后推平
        //再来一轮 因为后面的数字总比前面的大 
        //如果回到了tpos还有剩余 那就继续向后处理 
        int i=tpos+1;
        while(tmpm>0&&i<=cnt){
            int kpr=abs(pos[i]-pos[i-1]);//相对差值，要把前1～tpos全部加上这么多
            int lsr=kpr*ans;
            if(tmpm>=lsr){
                tmpm-=lsr;
                ans+=num[i];
            }
            else{
                int lskk=tmpm/kpr;
                //真实能抵消的数量 剩下的绝对不能再用了 向下会减少 向上不能更多
                ans+=lskk;
                break;
            }
            i++;
        }
        cout<<ans<<"\n";
        //print();
    }
    cout<<flush;
    return 0;
}//512041