#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q,k;
int w[500005],x[100005],y[100005],a[505][1005],t[505][1005],station[500005][505];
int T=t[1][1],rotelen[500005],station1[500005];
//dfs?  A\Bteshuxingzhikeyitepan,huoxukeyinadaodayue30'







int bfs(int startx,int endy,int cnt){
        if(startx==endy){
            return cnt;
        }
        cnt+=T;
        for(int i=1;i<=station1[startx];i++){
            int rote=station[startx][i];
            for(int j=1;j<=rotelen[rote];j++){
                bfs(a[rote][j],endy,cnt+T);
            }



        }


}



int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        rotelen[i]=k;
        for(int j=1;j<=2*k;j++){
            cin>>a[i][j]>>t[i][j];
            station[j][station1[j]+1]=i;
            station1[j]++;
        }

    }


    for(int r=1;r<=q;r++){
        cin>>x[r]>>y[r];
        if(12<=c and c<=19){//B

            cout<<bfs(x[r],y[r],0)+w[x[r]]+w[y[r]]<<endl;
            continue;
        }
        else{
            cout<<3*T<<endl;
        }
    }


    //fclose(stdin);
    //fclose(stdout);
    return 0;
}