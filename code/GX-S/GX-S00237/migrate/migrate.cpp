#include<bits/stdc++.h>
using namespace std;

const int N=2000010;


int c,t,n,d,x[N];
int dist[N][N],dists[N];
int idx,h[N],ne[N],e[N];
bool st[N];
int res=0;

void ad(int a,int b){
    ne[idx]=h[a],e[idx]=b,h[a]=idx++;
}



void Dis(){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int w=abs(x[i]-x[j]);
            dist[i][j]=w;
            if(w<=d){
                ad(i,j);
                ad(j,i);
            }
        }
    }
}


void Fin(int t){
    for(int k=1;k<=n;k++){

        for(int i=h[k];i!=-1;i=ne[i]){
            int j=e[i];

        dists[j]=min(dists[j],dists[k]+dist[k][j]);
        }
    }

    int o=dists[t];
    if(st[o])res++;
    else{
        st[o]=true;
    }

}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);


    priority_queue<int,vector<int>,greater<int>>heap;

    cin>>c>>t;

    while(t--){
        memset(x,0,sizeof x);
        memset(dist,-1,sizeof dist);
        cin>>n>>d;

        for(int i=1;i<=n;i++){
            scanf("%d",&x[i]);
        }

        Dis();


        for(int i=1;i<=n;i++){
        Fin(i);
        }


        printf("%d",res);
    }

    return 0;
}
