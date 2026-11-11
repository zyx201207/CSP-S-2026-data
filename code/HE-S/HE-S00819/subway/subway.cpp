#include<iostream>
#include<cstdio>
using namespace std;
long long w[500010];
long long k[500010];
long long c,n,m,d,p;
struct Xian{
    long long hao[50010];
    long long time[50010];
};
Xian xian[505];
long long zui=99999999;
void dfs(long long x,long long y,long long ans,long long sum){
    if(x==y){
        if(ans<zui){
            zui=ans;
        }
        return;
    }
    for(long long i=sum;i<=n;i++){
        for(long long j=1;j<=k[i];j++){
        	if(xian[i].hao[j]==x+1){
                ans+=xian[i].time[j];
                dfs(x+1,y,ans,i);
                ans-=xian[i].time[j];
            }
        	if(xian[i].hao[j]==xian[i+1].hao[1]){
        		i++;
        		j=1;
        		ans+=xian[i].time[j];
			}
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(long long i=1;i<=m;i++){
        cin>>w[i];
    }
    for(long long i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>xian[i].hao[j]>>xian[i].time[j];
        }
    }
    for(long long a=0;a<p;a++){
        zui=9999999999999;
        long long x,y;
        cin>>x>>y;
        long long ans=w[x]+w[y]+xian[1].time[1];
        dfs(x,y,ans,1);
        cout<<zui<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

