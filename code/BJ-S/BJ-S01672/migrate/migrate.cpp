#include<bits/stdc++.h>
#define int long long
using namespace std;
int len[2001][2001];
int countts[2001][2001];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,T;

    cin>>c>>T;
    for(int t=0;t<T;t++){
        int n,d;
        cin>>n>>d;
        vector<int> la(n+2);

        cin>>la[0];
        for(int i=1;i<n;i++){
            cin>>la[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(abs(la[i]-la[j])<=d){
                    len[i][j]=2;
                    len[j][i]=len[i][j];
                }else{
                    len[i][j]=10000001;
                    len[j][i]=len[i][j];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                countts[i][j]=0;
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i!=j){
                        if(len[i][j]>len[i][k]+len[k][j]-1){
                            countts[i][j]=0;
                            countts[j][i]=0;
                        }else if(len[i][j]==len[i][k]+len[k][j]-1){
                            countts[i][j]++;
                            countts[j][i]++;
                        }
                        len[i][j]=min(len[i][k]+len[k][j]-1,len[i][j]);
                        len[j][i]=len[i][j];
                    }
                }
            }
        }
        int cou=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(countts[i][j]==2){
                    cou++;
                    countts[j][i]=0;
                }
            }
        }
        cout<<cou<<'\n';
    }
    return 0;
}
