//freopen
//jiancedao kards huijiadiyijianshidakaikazijjc150jinbiyiciwofeichangdiankuangdeguozhuguofaguomengguosanzhangchetuitankehaiyoufuchongmengbigesheinengruhewozhengzaixunzhaodirenwocaowandanshigoucaodemeifenqishou131fujizhebayexvyoudebanxiwangduimianshoupailanshenmet26466haiyoulanhuishiyintoupijiaohuanchenghouqiwohaiyoubisimaidoudishengmechengjietaolizhanshaxiangoucaodejinugoucaodemeifengoucaodebingdaoren1939gongzuoshikuairangmeifensiyisiburanwojiumanhadunnidegongzuoshi!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <bits/stdc++.h>
using namespace std;
int n,m,a[999999],b[999999],c[999999];
queue<int> q,qq;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<999998;j++){
            b[j]=0;
        }
        for(int j=i;j<n;j++){
            if(b[a[j]]){
                while(q.front()!=a[j]){
                    qq.push(q.front());
                    q.pop();
                }
                while(q.size()){
                    b[q.front()]--;
                    q.pop();
                }
                while(qq.size()){
                    q.push(qq.front());
                    qq.pop();
                }
            }
            q.push(a[j]);
            b[a[j]]=1;
        }
        while(q.size()){
            c[q.front()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<' ';
    }
    return 0;
}
