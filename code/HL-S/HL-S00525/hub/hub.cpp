#include <bits/stdc++.h>

using namespace std;
const int N=1e6+5;
int woshiheyao,t,n,k,ma,d[N],lj[N],zlj[N],hy;
vector<int> v[N];
bool pd;
void dfs(int x,int f){
    d[x]=d[f]+1;
    if(d[x]>d[ma]){
        ma=x;
        if(pd)
            for(int i=1;i<=hy;i++)
                zlj[i]=lj[i];
    }
    for(auto y : v[x]){
        if(y==f)
            continue;
        lj[++hy]=y;
        dfs(y,x);
        hy--;
    }
    return ;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&woshiheyao,&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            v[i].clear();
            d[i]=0;
        }
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if(n&1){
            pd=1;
            for(int i=1;i<=n/2;i++){
                if(i==1){
                        sort(v[i].begin(),v[i].end());
                   // cout<<v[i][0]<<" "<<v[i][1]<<" "<<i+n/2+1<<"\n";
                    if(v[i][0]==i+1&&v[i][1]==i+n/2+1){

                    }
                    else{
                            //cout<<i<<"\n";
                        pd=0;
                        break;
                    }
                }
                else if(v[i].size()!=3){
                    pd=0;
                   // cout<<i<<"\n";
                    break;
                }
                sort(v[i].begin(),v[i].end());
                if((i==1)||(v[i][0]==i-1&&v[i][1]==i+1&&v[i][2]==i+n/2+1)){

                }
                else{
                   //     cout<<i<<"\n";
                    pd=0;
                    break;
                }
            }
            if(pd){
                    //cout<<1;
                if(k==n)
                    printf("0\n");
                else if(k>=n/2){
                    printf("1\n");
                }
                else{
                    printf("%d\n",(n/2-k-1)/4+1);
                }
                continue;
            }
        }
        if(k==2){
            pd=0;
            ma=1;
            hy=0;
            d[0]=1;
            lj[++hy]=0;
            dfs(1,0);
            hy=0;
            pd=1;
            lj[++hy]=ma;
            int g=ma;
            d[0]=0;
            dfs(ma,0);
            hy=d[ma];
            //cout<<ma<<" ";
           // cout<<hy<<" ";
           // for(int i=1;i<=hy;i++)
           //     cout<<zlj[i]<<" ";
            priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
            int ans=1e9;
            vector<int> bx;
            bx.push_back(0);
            int wozhenshiheyao=0;
            for(int i=max(hy/4-5,1);i<=min(hy/4+5,n);i++)
                bx.push_back(zlj[i]),wozhenshiheyao++;
            for(int i=max(hy/4+hy/2-5,1);i<=min(hy/4+hy/2+5,n);i++)
                bx.push_back(zlj[i]);
            int heyaolaidabisai=bx.size();
            for(int i=1;i<=wozhenshiheyao;i++){
                for(int j=1;j<=heyaolaidabisai-wozhenshiheyao;j++){
                    if(bx[i]<1||bx[j]<1||bx[i]>n||bx[j]>n)
                        continue;
                    if(i==j)
                        continue;
                    if(bx[i]==bx[j])
                        continue;
                    while(!q.empty())
                        q.pop();
                    for(int asdf=1;asdf<=n;asdf++)
                        d[asdf]=1e9;
                    int sum=0;
                    q.push({0,bx[i]});
                    q.push({0,bx[j]});
                    d[bx[i]]=0;
                    d[bx[j]]=0;
                    while(!q.empty()){
                        auto [z,x]=q.top();
                        q.pop();
                        if(d[x]!=z)
                            continue;
                        for(auto y : v[x]){
                            if(d[y]>z+1){
                                d[y]=z+1;
                                q.push({d[y],y});
                                sum=max(sum,d[y]);
                            }
                        }
                    }

                    ans=min(ans,sum);
                }
            }
            printf("%d\n",ans);
            continue;
        }
        printf("0\n");
    }
    return 0;
}

