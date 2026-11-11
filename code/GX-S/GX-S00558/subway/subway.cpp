#include<bits/stdc++.h>
using namespace std;

//teach me how to write
//teach me how to write
//teach me how to write
//teach me how to write
//teach me how to write

int c,n,m,d,q;//c:hyw
int tosubway[125414];
int subways[555][125414];

long long sub(long long sum,int canuse_subway[],int canuse_zhandian[],int in,int to,int where);
long long zhan(long long sum,int canuse_subway[],int canuse_zhandian[],int in,int to,int where);
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    if(c==0) cout << "I am is yangli! I am is yangli!" << endl;//hyw
    int t[m+1];
    for(int i=1;i<=m;i++) t[i]=i;
    int t1[n+1];
    for(int i=1;i<=n;i++) t1[i]=i;

    for(int i=1;i<=m;i++){
        cin >> tosubway[i];
    }
    for(int i=1;i<=n;i++){
        int zhanshu;
        cin >> zhanshu;
        int aaa;
        for(int j=1;j<=zhanshu;j++) cin >> aaa >> subways[i][aaa];
    }
    for(int i=1;i<=q;i++){
        int a,b;
        cin >> a >> b;
        long long sum=tosubway[a]+tosubway[b];
        cout << sub(sum,t,t1,a,b,0) << endl;
    }
    return 0;
}

long long sub(long long sum,int canuse_subway[],int canuse_zhandian[],int in,int to,int where){//subway search
    if(in==to) return subways[where][to];
    long long maxx=1e17;
    int t[m+1];
    for(int j=1;j<=m;j++){//avoid turn back
        t[j]=canuse_subway[j];
    }
    for(int i=1;i<=m;i++){
        if(subways[i][in]!=0 && t[i]!=0){
            t[i]==0;
            maxx=min(zhan(sum+subways[i][in],t,canuse_zhandian,in,to,i),maxx);
        }
    }
    return sum+=maxx;
}

long long zhan(long long sum,int canuse_subway[],int canuse_zhandian[],int in,int to,int where){//zhandian search
    long long maxx=1e17;
    int t[n+1];
    for(int j=1;j<=n;j++){//avoid turn back
        t[j]=canuse_zhandian[j];
    }
    for(int i=1;i<=n;i++){
        if(subways[where][i]!=0 && t[i]!=0){
            t[i]=0;
            maxx=min(sub(sum,canuse_subway,t,i,to,where),maxx);
        }
    }
    return maxx+sum;
}
