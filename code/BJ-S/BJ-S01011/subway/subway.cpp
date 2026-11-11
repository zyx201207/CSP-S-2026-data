#include <bits/stdc++.h>

using namespace std;

int dc[10086];
int dc1[10086][10086];
int a[10086];
vector<int> mape[10086];

vector<int> azui;
int cur = 0;
int dfs(int fa,int pos,int endp){
    //cout<<pos<<" ";
    if(pos == endp){//cout<<"fpin";
		return dc1[fa][endp];}
    else{
        azui.push_back(pos);
        int kq = azui.size()-1;
        int lim = 10086;
        for(auto iz:mape[pos]){
            bool lhg = false;
            for(auto bb:azui){
                    //cout<<bb<<"*";
                if(iz == bb){lhg = 1;break;
            }}
            if(lhg)continue;
            //cout<<endl;
            //cout<<iz<<"{";
            int ob = dfs(pos,iz,endp);
            //cout<<"["<<ob<<"]";
            if(ob == 0){continue;}
            if(ob< lim)lim = ob;
        }
        //cout<<"+"<<lim<<"+";
        //cout<<"&&"<<lim+dc[pos]<<"&&"<<endl;
        if(lim == 10086)return 0;
        azui[kq] = -1111111;
        return lim + dc[pos];
    }
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }//zuihoujia
    memset(dc,0,sizeof(dc));
    for(int j=1;j<=n;j++){
        int z;
        cin>>z;
        int line[z];
        for(int i=0;i<z;i++){
            cin>>line[i];
            int temp;
            cin>>temp;
            dc[line[i]]+=temp;
            if(i==0)continue;
            dc1[line[i-1]][line[i]] = temp;
            //cout<<line[i];
        }
        //cout<<endl;
        for(int i=0;i<z;i++){
            for(int j=0;j<z;j++){
                if(line[i]==line[j])continue;
                else{
                    mape[line[i]].push_back(line[j]);
                    //cout<<line[i]<<"-"<<line[j]<<endl;
                }
            }
        }
        //cout<<endl;
        // int c1;
        // cin>>c1;
        // int c2,temp;
        // cin>>temp;
        // dc[c1]+=temp;
        // for(int k=1;k<z;k++){
        //     cin>>c2;
        //     mape[c1].push_back(c2);
        //     mape[c2].push_back(c1);
        //     c1 = c2;
        //     temp = 0;
        //     cin>>temp;
        //     dc[c2]+=temp;
        // }
    }
    for(int bc = 0;bc<q;bc++){
        int x,y;
        cin>>x>>y;
        cout<<a[x]+a[y]+dfs(-1,x,y)<<endl;
    }
}
