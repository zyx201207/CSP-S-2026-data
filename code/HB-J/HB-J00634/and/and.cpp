#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1111111];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    int ans = 1,maxn = 0;
    for(int i = 1;i<=n;i++){
            ans = a[i];
        for(int j = i+1;j<=n;j++){
            ans&=a[j];
        }
    maxn = max(maxn,ans);
    }
    cout<<maxn;
    return 0;
}
/*juewangle,hongwenle,
struct node{
    string erjin;
    int chang;

}x[11111111];
struct nod2{
    queue<int>p;
    int jici,shu;
}y[1111111];
bool cmp(nod2 a,nod2 b){
    return a.shu>b.shu;
}
bool cmp1(nod2 a,nod2 b){
    if(a.shu == 0 && b.shu == 0) return a.jici>b.jici;
    else if(a.shu == 0 && b.shu!=0) return b.shu>a.shu;
    else if(a.shu!=0 && b.shu == 0) return a.shu>b.shu;
    return a.jici>b.jici;
}
signed main(){
    int n,m,a[111111];
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        int b = a[i];
        int cnt = 0;
        while(b){
            cnt++;
            x[i].erjin+=b%2+'0';
            if(b%2 == 1) {
                y[cnt].shu++;
                y[cnt].jici = cnt;
                y[cnt].p.push(a[i]);

            }
            b/=2;
        }
        for(int j = 0;j<cnt/2;j++){
            swap(x[i].erjin[j],x[i].erjin[cnt-j-1]);
        }

    }
    sort(y+1,y+1+25,cmp);
    int k = 1;
    bool flag = false;
    int ren = y[1].shu;
    int wei,ans = 0;
    while(ren>=m){
         if(!flag)sort(y+1,y+1+25,cmp1);
         while(y[k].shu>m){
            y[k].shu = 0;
            k++;
         }
         if(!flag)wei = k;
         if(!flag) {
            int ershu = 1;
            for(int i = 1;i<=y[k].jici;i++) ershu*=2;
            ans+=ershu;
            flag = true;

         }else{
             int len = y[wei].p.size();
             int len1 = y[k].p.size();

             for(int i = 1;i<=len1;i++){
                for(int j = 1;j<=len;j++){
                    bool fflag = false;
                    if(y[k].p.first() == y[wei].p.first()) {
                        fflag = true;
                        break;
                    }
                    y[wei].p.push(y[wei].top);
                    y[wei].p.pop();
                }
                if(fflag == false) y[k].pop();
             }
             if(y[wei].p.size()>y[k].p.size()) {
                len = y[wei].p.size();
                len1 = y[k].p.size();
                for(int i = 1;i<=len;i++){
                    for(int j = 1;j<=len1;j++){
                        bool fflag = false;
                        if(y[k].p.top() == y[wei].p.top()) {
                            fflag = true;
                            break;
                        }
                        y[k].p.push(y[k].top);
                        y[k].p.pop();
                    }
                    if(fflag == false) y[wei].pop();
                }
             }

           // while()
         }
    }
    cout<<ans;
    return 0;
}
*/
