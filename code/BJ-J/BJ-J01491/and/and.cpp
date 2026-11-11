#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,ansid=1;
long long f[200005][60],maxid,vis[200005],lastvis[200005];
vector <int> tot[60];
vector <int> wait;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        long long s=a[i],id=0;
        while(s>0){
            id++;
            if(s%2==1) f[i][id]=1;
            else f[i][id]=0;
            s/=2;
        }
        /*for(int j=1;j<=id;j++){
         cout<<f[i][j];
        }
        cout<<endl;*/
        maxid=max(maxid,id);
    }
    for(int i=maxid;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(f[j][i]==1){
                tot[i].push_back(j);
            }
        }
    }
    ans=0;
    for(int i=maxid;i>=1;i--){
        if(tot[i].size()>=m){
            for(int j=0;j<tot[i].size();j++){
                wait.push_back(tot[i][j]);
                vis[tot[i][j]]=1;
            }
            ansid=i;
            break;
        }
    }
    //cout<<ansid<<' ';
    int cont=0;
    for(int i=ansid;i>=1;i--){
        cont=0;
        int waits=1<<(i-1);
        for(int j=0;j<wait.size();j++){
            if((a[wait[j]]&waits)&&vis[wait[j]]==1) cont++;
        }
        if(cont>=m){
                //cout<<waits<<' '<<cont<<endl;
            for(int j=0;j<wait.size();j++){
                if(!(a[wait[j]]&waits)){
                    vis[wait[j]]=0;
                    //cout<<waits<<' '<<i<<endl;
                }
            }
            ans+=waits;
        }
    }
    cout<<ans;
    return 0;
}//120minutes!!!!!!!!!!!!!!!!!!!!
