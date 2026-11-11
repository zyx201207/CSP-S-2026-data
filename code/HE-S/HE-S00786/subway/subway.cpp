#include <bits/stdc++.h>
using namespace std;
long long limans=1E+9;
long long suum=0,pst;
long long c,n,m,d,q;
bool spclB=1;
bool vis[1005];
long long t[1005][1005];
struct subway{
	long long ida;
	long long w;
}sta[10005];
struct lines{
	long long a[1005];
	long long k;
}ls[1005];
struct plans{
    long long begg;
    long long endd;
}pl[1005];
void dfs(long long begnn,long long enddd){
    long long lins=0;
    bool lsisn=0,lsing=0;
    if(vis[begnn]!=1){
            vis[begnn]=1;
         suum++;
        for(long long i=1;i<=n;i++){
                if(i==pst){
                    continue;
                }
            for(long long j=1;j<=ls[i].k;j++){
                if(ls[i].a[j]==begnn){
                    lins=i;
                    lsisn=1;
                    break;
                }
            }
            if(lsisn==1){
                break;
            }
    }

    for(long long j=1;j<=ls[lins].k;j++){
        if(ls[lins].a[j]==enddd)
        {
            lsing =1;
            break;
        }


    }
    if(lsing==0){
        for(long long j=1;j<=ls[lins].k;j++){
            if(ls[lins].a[j]==begnn) continue;
        pst=lins;
        dfs(ls[lins].a[j],enddd);
        }
    }
    }

}
int main(){
	freopen("subway.in","r",stdin);
	freopen(" subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>sta[i].w;
	}
	for(long long i=1;i<=n;i++){
        cin>>ls[i].k;
        for(long long j=1;j<=ls[i].k;j++){
            cin>>ls[i].a[j];
            cin>>t[i][ls[i].a[j]];
        }
	}
	for(long long i=1;i<=q;i++){
        cin>>pl[i].begg>>pl[i].endd;
	}
	long long sB=t[1][ls[1].a[1]];
	for(long long i=1;i<=n;i++){
        for(long long j=1;j<=ls[i].k;j++){
            if(t[i][ls[i].a[j]]!=sB){
                spclB=0;
                break;
            }

        }
        if(spclB==0){
            break;
        }

	}

	memset(vis,0,1005);
	if(spclB){
        for(long long i=1;i<=q;i++){
            dfs(pl[i].begg,pl[i].endd);

            cout<<(((suum-1)*2)*sB)+sta[pl[i].begg].w+sta[pl[i].endd].w<<endl;
        }
	}
	return 0;
}
