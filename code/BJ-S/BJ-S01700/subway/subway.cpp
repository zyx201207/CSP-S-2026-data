#include<bits/stdc++.h>
using namespace std;
struct way{
    int k;
    map<int,int>st;

};
struct g{
    int x;
    int num;
};
int c,n,m,d,qqr;
int st[500+5];
int a[500+5][500+5];
int cx[100000][2];
way sw[500000+10];
int answer[100000+5];

int bfs(int x,int y){
    int mp[500+5];
    for(int i=1;i<=n;i++){
        mp[i]=-1;
    }
    queue<int>q;
    long long mn=100;
    q.push(x);
    mp[x]=st[x];
    while(!q.empty()){
        //cout<<111;
        int s=q.front();
        q.pop();
        //cout<<s<<endl;
        //if(mp[s]>mn)break;
        for(int i=1;i<=n;i++){
            if(a[s][i]!=-1){
                if(mp[i]==-1){
                    //cout<<"a";
                    mp[i]=a[s][i]+mp[s];
                    q.push(i);
                }
                else{
                    //cout<<"b";
                    if(mp[i]>mp[s]+a[s][i]){
                        mp[i]=a[s][i]+mp[s];
                        q.push(i);
                        //cout<<mp[i]<<endl;
                        //cout<<"c";
                    }
                }
                //cout<<' '<<s<<' '<<i<<' '<<mp[i]<<' '<<a[s][i]<<' '<<mp[s]<<endl;
            }
        }
    }
    //for(int i=1;i<=n;i++)cout<<mp[i]<<' ';
    //cout<<endl;
    for(int i=1;i<=qqr;i++){
        if(cx[i][0]==x){
            answer[i]=mp[cx[i][1]]+st[cx[i][1]];
        }
    }
    return mp[y]+st[y];




}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>qqr;
    for(int i=1;i<=n;i++)cin>>st[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=-1;
        }
    }
    for(int i=1;i<=m;i++){

        cin>>sw[i].k;
        for(int j=1;j<=sw[i].k;j++){

            int x,y;
            cin>>x>>y;
            //cout<<sw[i].k<<' '<<j<<endl;
            for(auto it=sw[i].st.begin();it!=sw[i].st.end();it++){
                if(a[it->first][x]==-1){
                    a[it->first][x]=it->second+y;
                    a[x][it->first]=it->second+y;

                }
                else{
                    a[it->first][x]=min(a[it->first][x],it->second+y);
                    a[x][it->first]=min(a[x][it->first],it->second+y);
                }
            }
            sw[i].st[x]=y;
        }
    }
    for(int r=1;r<=qqr;r++){
        cin>>cx[r][0]>>cx[r][1];
    }
    for(int i=1;i<=qqr;i++)if(answer[i]==0)answer[i]=bfs(cx[i][0],cx[i][1]);

    for(int i=1;i<=qqr;i++)cout<<answer[i]<<endl;
    return  0;
}
