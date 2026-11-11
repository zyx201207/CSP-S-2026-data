#include<bits/stdc++.h>
using namespace std;

long long dao[3][500005]={{{0}}};

int main(){

    freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
     int n,d,c,t;
    cin >> c >> t ;
    int jjj[20000]={0};
    for(int i=1 ; i<=t ; i++){
        cin >> n >> d;

        for(int j=1;j<=n;j++){
            cin>>dao[0][j];
            dao[1][j]=dao[0][j]-dao[0][j-1];
        }

        dao[1][1]=0;
        for(int j=2;j<=n;j++){
            if(dao[1][j]-dao[1][j-1]>d) {
                dao[2][j]=-9999999;
                continue;
            }
            int coun=dao[1][j];
            for(int x=j-1;x>=1;x--){
                if(dao[1][x]+coun<=d){
                    coun+=dao[1][x];
                }
                dao[2][j]=dao[0][j]-coun;
                jjj[dao[0][j]-coun]++;
            }
        }
        int uu=0;
        for(int j=4;j<=n;j++){
            for(int x=1;j-x>=3;x++){
                for(int y=x+1;y<=j;y++){
                    if(dao[2][y]==-9999999){
                        break;
                    }
                    if(jjj[dao[2][y]]>=2 && dao[2][y]==dao[2][y+1]){
                        uu++;
                        break;
                    }
                }
            }
        }
        cout<<uu<<endl;


    }
    return 0;
  }



