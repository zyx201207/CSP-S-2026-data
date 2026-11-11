/*
1624:开C，这什么玩意？
1630:考虑简单分咋做。
1631:温馨提示，还剩2h。
1633:开龙龙，考虑A
1634:设差为m，如果d<2*m就是0个
否则，设g=floor(d/m)那么答案就是n-(2g-1)+1
1636:实践一下！
1642:飞得太远也不行。
1643:8pts get.
1646:发现了一个性质：是那个什么双岛的(i,j)一定存在一个k，
使得i能够直接到k和k+1,k和k+1能直接到j，
但是k-1不能直接到j且i不能直接到k+2.
1650:我们先前缀和一下。再枚举i,j，二分第一个k使得sum[k]-sum[i-1]>m.
然后就验证以下，可以就可以，不可以就不可以。
1702:WA了。
1717:Some Body怎么调不对！！！
1722:漏了情况，海盗可以两边按照恰好为d的进行扩展。
1726:我福了。
1727:还有1h。
1735:感觉救不回来了有点。
1736:哀，我不明白为什么。
1737:赶紧写O(buzhidao)吧。
1754:写不出来，总是错。跳题。
*/
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long _,n,d,a[N],sum[N],b[N],step;
vector<int> tt;
void dfs(int now,int sta,int tar,int sheng){
    //cout<<now<<" "<<sta<<" "<<tar<<" "<<sheng<<"\n";
    if(now==tar){
        tt.push_back(tar);
        int la=sta;
        for(auto v : tt){
            if(b[v]-b[la]>d)return ;
            v=la;
        }
        step++;
        return ;
    }
    if(sheng){
        tt.push_back(now);
        dfs(now+1,sta,tar,sheng-1);
        tt.pop_back();
    }
    else if(sheng<tar-now)dfs(now+1,sta,tar,sheng);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>_>>_;
    while(_--){
        bool TA=1;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=a[i]-a[1]+1;
            sum[i]=sum[i-1]+b[i];
            if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])TA=0;
        }
        if(n<=3){
            cout<<"0\n";
            continue;
        }
        if(TA){
            long long m=a[2]-a[1],g=d/m,ttmp=n-(2*g-1);
            if(d<2*m||ttmp<=0)cout<<"0\n";
            else cout<<ttmp<<"\n";
            continue;
        }
        if(n<=5000){
            long long ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+3;j<=n;j++){
                    if(b[j]-b[i-1]<=d){
                        continue;
                    }
                    /*
                    long long more=0;
                    for(int k=i;k<j;){
                        long long tmp=0;
                        while(tmp+b[k+1]-b[k]<=d&&k<j)tmp+=b[k+1]-b[k],k++;
                        more++;
                    }
                    step=0;
                    dfs(i+1,i,j,more-1);
                    if(step==2)ans++;*/
                    
                    long long l=i+2,r=j,tmp=-1;
                    while(l<=r){
                        long long mid=(l+r)>>1;
                        if(b[mid]-b[i]>d)tmp=mid,r=mid-1;
                        else l=mid+1;
                    }
                    if(tmp==-1)continue;
                    tmp--;
                    if((b[j]-b[tmp-1]<=d)&&(b[tmp+1]-b[i]>d)
                    &&(b[j]-b[tmp-2]>d)){
                        l=1,r=1;
                        int ti=i,tj=j;
                        while(ti>1&&b[ti]-b[ti-1]==d)ti--,l++;
                        while(tj<n&&b[tj+1]-b[tj]==d)tj++,r++;
                        ans+=l*r;
                    }
                }
            }
            cout<<ans<<"\n";
            continue;
        }
    }
    return 0;
}