#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500009],x,y,zh,zong=0,dd[1009][1009];
vector<long long> ve[509];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
cin>>w[i];
}
long long du;
for(int i=1;i<=n;i++){
cin>>zh;
ve[i].push_back(zh);
for(int j=1;j<=ve[i][0]*2;j++){
    cin>>du;
    ve[i].push_back(du);
}
}
for(int i=1;i<=m;i++){
for(int j=i+1;j<=m;j++){
dd[i][j]=dd[j][i]=10000000000000000;//uo
}}
for(int i=1;i<=n;i++){
for(int j=1;j<=ve[i][0];j++){
for(int k=j+1;k<=ve[i][0];k++){
   dd[ve[i][j*2-1]][ve[i][k*2-1]]=min(dd[ve[i][j*2-1]][ve[i][k*2-1]],ve[i][j*2]+ve[i][k*2]);
   dd[ve[i][k*2-1]][ve[i][j*2-1]]=min(dd[ve[i][k*2-1]][ve[i][j*2-1]],ve[i][j*2]+ve[i][k*2]);
    //if(dd[1][3]==0)cout<<i<<j<<k<<endl;
}
}
}

for(int k=1;k<=m;k++){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            dd[i][j]=min(dd[i][j],dd[i][k]+dd[k][j]);
            dd[j][i]=dd[i][j];
        }
    }

}
for(int i=1;i<=q;i++){
zong=0;
cin>>x>>y;
zong+=w[x];
zong+=w[y];
//cout<<x<<y<<zong<<" ";
zong+=dd[x][y];

cout<<zong<<endl;
}
return 0;
}
