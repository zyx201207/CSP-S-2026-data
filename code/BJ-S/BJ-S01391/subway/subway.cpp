#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int c;
long long int n,m,d,q;
long long int w[500010];
long long int k[510];
long long int ans;
long long int t;
long long int dj[510];
int fa[510];

struct edge{
    int u,v;
    int w;
};

//priority_queue<edge,vector<int>,greater<int>> pq;

vector<edge> pq;

struct station{
    int a,t;
}st[510][510];

int g[510][510];

bool cmp1(edge x,edge y){
    return x.w<y.w;
}

bool cmp(station x,station y){
    return x.a<y.a;
}


void dijistra(int m){
    for(int i=1;i<=m;i++){
        if(g[1][i]!=0){
            edge e;
            e.u=1,e.v=i,e.w=g[1][i];
            //pq.push(e);
            pq.push_back(e);
        }
    }

    sort(pq.begin(),pq.end()+1,cmp1);

    while(!pq.empty()){
        int a=pq[0].u,b=pq[0].v;
        dj[b]=dj[a]+pq[0].w;
        pq.erase(pq.begin(),pq.begin()+1);

        for(int i=1;i<=m;i++){
            if(g[b][i]!=0){
                //pq.push({b,i,g[b][i]});
                pq.push_back({b,i,g[b][i]});
            }
        }
        sort(pq.begin(),pq.end()+1,cmp1);
        //pq.pop();

    }

}

int main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
        cin>>w[i];
	}
	for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int a,t;
            cin>>st[i][j].a>>st[i][j].t;
        }
        sort(st[i]+1,st[i]+k[i]+1,cmp);
        for(int x=1;x<=k[i];x++){
            for(int y=x+1;y<=k[i];y++){
                g[y][x]=g[x][y]=st[i][x].t+st[i][y].t;
            }
        }
	}

	//dijistra(m);


	while(q--){
        int x,y;
        t=0;
        cin>>x>>y;
        ans=0;
        if(x>y){
            swap(x,y);
        }

        ans+=w[x]+w[y];

        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(x==st[i][j].a){
                    t+=st[i][j].t;
                }
                if(y==st[i][j].a){
                    t+=st[i][j].t;
                }
            }
        }


        cout<<ans+t<<endl;

	}


	return 0;
}
