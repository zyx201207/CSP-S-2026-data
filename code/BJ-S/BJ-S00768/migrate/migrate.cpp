#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+2;
int c,T;
int n,d,ans=0;
vector<int> island;
vector<vector<int>>islands,islands2;
int ingo(){
    ans=0;
    island.clear();
    cin>>n>>d;
    for(int i=0;i<n;i++){
        vector<int>temp1,temp2;
        for(int j=0;j<n;j++){
            temp1.push_back(0);
            temp2.push_back(1);
        }
        islands.push_back(temp1);
        islands2.push_back(temp2);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        island.push_back(x);

        for(int j=0;j<=i;j++){
            islands[j][i]=(abs(island[j]-island[i])<=d);
        }
    }
    for(int k=n-2;k>=1;k--){
        for(int i=k-1;i>=0;i--){
            for(int j=n-1;j>=k+1;j--){
                int nr=islands[i][k]+islands[k][j];
                if(islands[i][k]&&islands[k][j]&&((nr<islands[i][j])||!islands[i][j])){
                    islands[i][j]=nr;
                    islands2[i][j]=1;
                }
                else if(nr==islands[i][j]) islands2[i][j]++;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(islands2[i][j]==2) ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--) ingo();
    return 0;
}
