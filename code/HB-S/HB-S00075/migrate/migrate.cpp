#include <bits/stdc++.h>
using namespace std;

int c,T;
long long n,d;
long long a[5000+10];
pair<int,int> f[5000+10][5000+10];
vector<int> to[5000+10];
queue<int> res;bool isin[5000+10];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> T;
    while(T--){
        cin >>n >> d;
        for(int i=1;i<=n;i++)cin >> a[i];
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]={0x7f7f7f7f,0};
        for(int i=1;i<=n;i++)f[i][i]={0,1};
        for(int i=1;i<=n;i++)to[i].clear();
        while(!res.empty())res.pop();

        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    to[i].push_back(j);
                }
            }
        }

        for(int i=1;i<=n;i++){
            res.push(i);isin[i]=1;
            while(!res.empty()){
                int x=res.front();res.pop();isin[x]=0;
                if(f[i][x].second>2)continue;
                for(auto y:to[x]){
                    if(f[i][y].first>f[i][x].first+1){
                        f[i][y].first=f[i][x].first+1;
                        f[i][y].second=f[i][x].second;
                        if((!isin[y])&&f[i][y].second<=2){
                            res.push(y);
                            isin[y]=1;
                        }

                    }
                    else if(f[i][y].first==f[i][x].first+1){
                        f[i][y].first=f[i][x].first+1;
                        f[i][y].second+=f[i][x].second;
                        if((!isin[y])&&f[i][y].second<=2){
                            res.push(y);
                            isin[y]=1;
                        }
                    }
                    //cout << i << ':'<<x<<'/'<<y<<':'<<f[i][y].first << ' '<<f[i][y].second<<endl;
                }
            }
        }

        long long cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                //cout << i << '/'<<j <<':'<<f[i][j].second<<endl;
                if(f[i][j].second==2)cnt++;
            }
        }cout << cnt << endl;
    }
    return 0;
}
