#include<bits/stdc++.h>
//define int long long
using namespace std;
int c,n,m,d,q,ans;
int kou[1005];
int a[1005][1005];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    //cout<<2;
    if(c>=7&&c<=11){
        //cout<<1;
        for(int i=1;i<=m;i++)cin>>kou[i];
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            //cout<<i<<endl;
            if(k==1){
                int x,y;
                cin>>x>>y;
                break;
            }
                int st,stt,en,ent;
                cin>>st>>stt>>en>>ent;
                //cout<<st<<' '<<stt<<' '<<en<<' '<<ent<<endl;
                if(a[st][en])a[st][en]=a[en][st]=min(a[st][en],stt+ent);
                else a[st][en]=a[en][st]=stt+ent;


        /*for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                cout<<a[i][j]<<' ';
            }cout<<'\n';
        }cout<<'\n';}*/
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(i==j)continue;
                if(a[i][j]>0){
                    for(int k=1;k<=m;k++){
                        if(i==k)continue;
                        if(a[j][k]==0)continue;
                        if(a[i][k])a[i][k]=a[k][i]=min(a[i][k],a[i][j]+a[j][k]);
                        else a[i][k]=a[k][i]=a[i][j]+a[j][k];
                    }
                }
            }
        }
        /*for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                cout<<a[i][j]<<' ';
            }cout<<'\n';*/
        }
        for(int i=1;i<=q;i++){
            int qid,zhd;
            //cout<<i<<':';
            cin>>qid>>zhd;
            cout<<a[qid][zhd]+kou[qid]+kou[zhd]<<'\n';
        }
    }

    else if(c<=15){
        //cout<<1;
        int ans=0;

        for(int i=1;i<=m;i++)cin>>kou[i];
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            //cout<<i<<endl;
            if(k==1){
                int x,y;
                cin>>x>>y;
                break;
            }
            int d[2][20005]={};
            for(int i=1;i<=k;i++){
                cin>>d[0][i]>>d[1][i];
            }

            for(int i=1;i<=k;i++){
                for(int j=i;j<=k;j++){
                    if(a[ d[0][i] ][ d[0][j] ])a[ d[0][i] ][ d[0][j] ]=a[ d[0][j] ][ d[0][i] ]=min(a[d[0][i]][d[0][j]],d[1][i]+d[1][j]);
                    else a[ d[0][i] ] [ d[0][j] ]=a[ d[0][j] ][ d[0][i] ]=d[1][i]+d[1][j];
                }
            }



       }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(i==j)continue;
                if(a[i][j]>0){
                    for(int k=1;k<=m;k++){
                        if(i==k)continue;
                        if(a[j][k]==0)continue;
                        if(a[i][k])a[i][k]=a[k][i]=min(a[i][k],a[i][j]+a[j][k]);
                        else a[i][k]=a[k][i]=a[i][j]+a[j][k];
                    }
                }
            }
        }

        for(int i=1;i<=q;i++){
            int qid,zhd;
            //cout<<i<<':';
            cin>>qid>>zhd;
            cout<<a[qid][zhd]+kou[qid]+kou[zhd]<<'\n';
        }
    }

    return 0;
}
