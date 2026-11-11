#include<bits/stdc++.h>
using namespace std;

#define MAXN 500009

#define ll long long

ll c,n,m,d,q,a,t,f_,s_,_f,_s;
ll statime[MAXN];
vector<pair<ll,ll> > station[MAXN];
vector<pair<ll,ll> > line_[509];
vector<pair<ll,ll> > line[509];
ll tu[509][509];//图
ll dp[509][509][3];
bool isok[509];
queue<int> qu;
int main(){
    //freopen("subway5.in","r",stdin);
    //freopen("subway5.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    ll i,j,k,l;
    for(i=0;i<505;i++){
        for(j=0;j<505;j++)tu[i][j]=2147483647000;
        for(j=0;j<505;j++)dp[i][j][1]=2147483647000;

        for(j=0;j<505;j++)dp[i][j][0]=2147483647000;
    }
    for(i=0;i<m;i++){
        cin>>statime[i];//输入从每个地铁站的地铁口走到站厅需要的时间
    }for(i=0;i<n;i++){
        cin>>k;
        for(j=0;j<k;j++){
            cin>>a>>t;a--;
            station[a].push_back(make_pair(i,t));//每一站加入pair<地铁编号,站台到站厅时间>
            line[i].push_back(make_pair(a,t));//地铁站列表加入pair<经过站的编号,站台到站厅的距离>
        }
    }
    //开始构建图
    for(i=0;i<n;i++){//遍历每条线
        for(j=0;j<line[i].size();j++){//遍历每条线经过的站
            f_=line[i][j].first;
            s_=line[i][j].second;
            for(k=0;k<station[f_].size();k++){//遍历每条线经过的站能换乘的线
                _f=station[f_][k].first;
                _s=station[f_][k].second;
                if(_f!=i){
                    tu[i][_f]=min(tu[_f][i],s_+_s);
                }
            }
        }
    }
    //寻找每两个地铁之间换乘距离和的最小值O(n^3)
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            dp[i][j][0]=tu[i][j];
            dp[i][j][(n+1)%2]=tu[i][j];
            if(c==7 || c==8 || c==9 || c==10 || c==11){
                if(tu[i][j]!=2147483647000 and i!=j){
                    line_[i].push_back(make_pair(j,tu[i][j]));
                }
            }
            if(i==j)dp[i][j][0]=0;
            if(i==j)dp[i][j][1]=0;
        }
    }
    if(c<=6 || c==20 || c==21){//O(n^4)
        for(i=1;i<=n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    dp[j][k][i%2]=dp[j][k][(i+1)%2];
                    for(l=0;l<n;l++){
                        if(j!=l and k!=l)
                        dp[j][k][i%2]=min(dp[j][k][i%2],dp[j][l][(i+1)%2]+dp[l][k][(i+1)%2]);
                    }
                }
            }
        }
    }

    if(c==7 || c==8 || c==9 || c==10 || c==11){

        for(i=1;i<=n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    dp[j][k][i%2]=dp[j][k][(i+1)%2];
                }
            }
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    for(l=0;l<line_[k].size();l++){
                        dp[j][line_[k][l].first][i%2]=min(dp[j][k][(i+1)%2]+line_[k][l].second,dp[j][line_[k][l].first][i%2]);
                    }
                }
            }
        }
    }

    if(c>=12 and c<=19){
        for(i=0;i<n;i++){

            for(j=0;j<n;j++)isok[j]=0;
            isok[i]=1;
            k=1;
            qu.push(i);
            dp[i][i][(n+1)/2]=0;
            tu[i][i]=0;
            while(k<n){
                l=qu.front();
                qu.pop();
                for(j=0;j<n;j++){
                    if(tu[l][j]!=2147483647000 and dp[i][l][(n+1)%2] != 2147483647000){
                        if(isok[j]==0){
                            dp[i][j][(n+1)%2]=dp[i][l][(n+1)%2]+tu[l][j];
                            k++;
                            qu.push(j);
                            isok[j]=1;
                        }
                    }if(tu[j][l]!=2147483647000 and dp[i][l][(n+1)%2] != 2147483647000){
                        if(isok[j]==0){
                            dp[i][j][(n+1)%2]=dp[i][l][(n+1)%2]+tu[j][l];
                            k++;
                            qu.push(j);
                            isok[j]=1;
                        }
                    }
                }
            }
        }
    }for(i=0;i<q;i++){
        cin>>k>>l;
        k--,l--;
        ll ans=21474836470000000,i1,i2;
        for(i1=0;i1<station[k].size();i1++){
            for(i2=0;i2<station[l].size();i2++){
                ans=min(ans,dp[station[k][i1].first][station[l][i2].first][(n+1)%2]+station[k][i1].second+station[l][i2].second);
            }
        }
        cout<<ans+statime[k]+statime[l]<<endl;
    }
}
