#include<bits/stdc++.h>
using namespace std;
vector<vector<long long> > minroad;
vector<vector<long long> > minr;
vector<long long> other;
vector<long long> k;
vector<vector<long long> > name;
vector<vector<long long> > t;
vector<long long> mark;
bool debug=0;
long long dfs(long long n,long long m){
    if(max(n,m)>minroad.size()-1||min(n,m)<=0){
        return 100000000;
    }
    long long de=-1;
    if(n==m){
        return 0;
    }
    if(minroad[n][m]!=0){
        return minroad[n][m];
    }
    mark[n]=1;
    long long sum=1000000;
    for(long long a=0;a<minr[n].size();a++){
        if(!mark[minr[n][a]]){
            if(min(sum,dfs(minr[n][a],m)+minroad[minr[n][a]][n])!=sum){
                de=minr[n][a];
            }
            sum=min(sum,dfs(minr[n][a],m)+minroad[minr[n][a]][n]);
        }
    }
    mark[n]=0;
    minr[n].push_back(m);
    minr[m].push_back(n);
    minroad[n][m]=sum;
    minroad[m][n]=sum;
    if(debug){
        cout<<n<<" "<<m<<" "<<de<<" "<<sum<<"--\n";
    }
    return sum;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);//*/
    long long a,c,d,n,m,q,x,y;
    cin>>c>>n>>m>>d>>q;
    mark.resize(m+1);
    minroad.resize(m+1);
    minr.resize(m+1);
    for(a=1;a<minroad.size();a++){
        minroad[a].resize(m+1);
        for(long long aa=1;aa<=m;aa++){
            minroad[a][aa]=0;
        }
    }
    other.resize(1);
    for(a=1;a<=m;a++){
        long long one;
        cin>>one;
        other.push_back(one);
    }
    k.resize(n+1);
    name.resize(n+1);
    t.resize(n+1);
    //cout<<"next";
    for(a=1;a<=n;a++){
        cin>>k[a];
        name[a].resize(k[a]+1);
        t[a].resize(k[a]+1);
        for(long long e=1;e<=k[a];e++){
            cin>>name[a][e];
            cin>>t[a][e];
            for(long long f=1;f<e;f++){
                //cout<<"\n"<<f<<" "<<min(name[a][e],name[a][f])<<" "<<max(name[a][e],name[a][f])<<"\n";
                if(minroad[min(name[a][e],name[a][f])][max(name[a][e],name[a][f])]==0){
                    minr[name[a][f]].push_back(name[a][e]);
                    minr[name[a][e]].push_back(name[a][f]);
                }//*/
                minroad[min(name[a][e],name[a][f])][max(name[a][e],name[a][f])] = (minroad[min(name[a][e],name[a][f])][max(name[a][e],name[a][f])]==0 ? t[a][e]+t[a][f] : min(minroad[min(name[a][e],name[a][f])][max(name[a][e],name[a][f])],t[a][e]+t[a][f]));
                minroad[max(name[a][e],name[a][f])][min(name[a][e],name[a][f])]=minroad[min(name[a][e],name[a][f])][max(name[a][e],name[a][f])];
            }//*/
        }
    }
    for(a=1;a<=q;a++){
        cin>>x>>y;
        if(x>y){
            swap(x,y);
        }
        if(a==4){
            debug=0;
        }
        if(a==5){
            debug=0;
        }
        cout<<dfs(x,y)+other[x]+other[y]<<"\n";
    }
}
