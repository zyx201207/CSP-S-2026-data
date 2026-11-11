#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,T,n,d,x[N],nxt[N][13],prv[N][13],sumn[N][13],sump[N][13];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>T;
    if(c==11||c==12){
        while(T--){
            cin>>n>>d;
            for(int i=1;i<=n;++i)cin>>x[i];
            int t=x[2]-x[1];
            if(n==1||t>d){
                cout<<"0\n";
                continue;
            }int cnt=d/t;
            if(cnt==1||n<cnt*2)cout<<"0\n";
            else cout<<n-cnt*2+1<<'\n';
        }
    }
    else if(c==13||c==14){
        while(T--){
            cin>>n>>d;
            for(int i=1;i<=n;++i)cin>>x[i];
            for(int i=1,pos=1;i<=n;++i){
                while(pos<n&&x[pos+1]-x[i]<=d)++pos;
                nxt[i][0]=pos;
            }for(int i=n,pos=n;i;--i){
                while(pos>1&&x[i]-x[pos-1]<=d)--pos;
                prv[i][0]=pos;
            }int pos=-1;
            for(int i=1;i<=n;++i)if(x[i]-x[1]<=d&&x[n]-x[i]<=d)pos=i;
            int cnt0=1,cnt1=0,cnt2=0,cnt3=0;
            for(int i=1;i<=n;++i){
                if(nxt[i][0]==pos)++cnt0;
                if(prv[i][0]==pos)++cnt1;
                if(nxt[i][0]==pos+1)++cnt2;
                if(prv[i][0]==pos-1)++cnt3;
            }cout<<cnt0*cnt3+cnt1*cnt2<<'\n';
        }
    }else{
        while(T--){
            cin>>n>>d;
            for(int i=1;i<=n;++i)cin>>x[i];
            for(int i=0;i<12;++i)nxt[N-1][i]=N-1;
            for(int i=1,pos=1;i<=n;++i){
                pos=max(i,pos);
                while(pos<n&&x[pos+1]-x[i]<=d)++pos;
                nxt[i][0]=sumn[i][0]=pos;
                if(pos==i){
                    nxt[i][0]=N-1;
                    sumn[i][0]=0;
                }
            }for(int i=n,pos=n;i;--i){
                pos=min(i,pos);
                while(pos>1&&x[i]-x[pos-1]<=d)--pos;
                prv[i][0]=sump[i][0]=pos;
                if(pos==i)prv[i][0]=sump[i][0]=0;
            }for(int j=1;j<13;++j)for(int i=1;i<=n;++i){
                nxt[i][j]=nxt[nxt[i][j-1]][j-1];
                sumn[i][j]=sumn[i][j-1]+sumn[nxt[i][j-1]][j-1];
                prv[i][j]=prv[prv[i][j-1]][j-1];
                sump[i][j]=sump[i][j-1]+sump[prv[i][j-1]][j-1];
            }int ans=0;
            // for(int i=1;i<=n;++i){
            //     for(int j=0;j<=12;++j)cout<<sumn[i][j]<<' ';
            //     cout<<endl;
            // }
            for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j){
                if(x[j]-x[i]<=d)continue;
                int tmp=i,sumnxt=0,sumprv=0;
                for(int k=12;k>=0;--k){
                    if(nxt[tmp][k]<j){
                        sumnxt+=sumn[tmp][k];
                        tmp=nxt[tmp][k];
                    }
                }tmp=j;
                for(int k=12;k>=0;--k){
                    if(prv[tmp][k]>i){
                        sumprv+=sump[tmp][k];
                        tmp=prv[tmp][k];
                    }
                }if(sumnxt==sumprv+1)++ans;
            }cout<<ans<<'\n';
        }
    }return 0;
}//g++ -O2 -Wall -Wextra c.cpp
//./a.out < migrate3.in > tmp.out
//diff -b tmp.out migrate3.ans
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/