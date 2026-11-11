#include <bits/stdc++.h>
using namespace std;
struct qujian{
    long long st;
    long long  en;
    char ch;
    long long len;
    bool jia;
    long long houst,houen;
};
qujian in[200010];
qujian q[200010],h[200010];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
  //  cin>>in[3].ch;
    //cout<<(int)in[3].ch;
    cin>>n;
    long long num=1,t1;
    char chin;
    //cout<<(int)in[3].ch;
    //return 0;
    for(int i=1;i<=n;i++) {
        in[i].st=num;
        cin>>t1;
        num+=t1;
        in[i].en=num-1;
        cin>>chin;
        in[i].ch=chin;
        //cout<<t1;
        in[i].len=t1;
        //cout<<i<<in[i].st<<in[i].en<<in[i].ch<<in[i].houst<<in[i].houen<<endl;
        //if(i==n){
         //   cout<<1;;
         //   break;
        //};
    }
    ///cout<<1;

    ///cout<<in[1].st<<in[1].en<<in[1].ch<<in[1].houst<<in[1].houen;//return 0;
    //system("pause");
    num=num-1;
    //cout<<1;
    for(int i=1;i<=n;i++) {
        //cout<<1;
        in[i].houst=num+1-in[i].en;
        in[i].houen=num+1-in[i].st;
        //cout<<1;
    }

    //cout<<in[1].st<<in[1].en<<in[1].ch<<in[1].houst<<in[1].houen;
    long long r=0,l=0;      //r .qianjisehu      l   .houkaishi
    if(num%2==0) {
        r=num/2;
        l=r+1;
    }else {
        r=(num-1)/2;
        l=r+2;
    }

    long long sqian=1,shou=num,qqian=1,qhou=n,index=0,now=1;
    //return 0;
    while(1) {
        index++;
        q[index].ch=in[qqian].ch;
        h[index].ch=in[qhou].ch;
        q[index].st=now;
        h[index].st=now;
        if(in[qqian].en==in[qhou].houen){
            now=in[qqian].en+1;
            q[index].en=now-1;
            h[index].en=now-1;
            qqian++;qhou--;
        }
        else if(in[qqian].en<in[qhou].houen) {
            now=in[qqian].en+1;
            q[index].en=now-1;
            h[index].en=now-1;
            qqian++;
        }
        else if(in[qqian].en>in[qhou].houen) {
            now=in[qhou].houen+1;
            q[index].en=now-1;
            h[index].en=now-1;
            qhou--;
        }
        if(now==(r+1)) break;
        if(now>(r+1)) {
            q[index].en=r;
            h[index].en=r;
            break;
        }
    }

    for(int i=0;i<index+10;i++) {
        q[i].len=q[i].en-q[i].st+1;
    }
    long long ans=0;
    for(int i=0;i<index+10;i++){
        if(q[i].ch!=h[i].ch) ans+=q[i].len;
    }
    cout<<ans;
    return 0;
}
