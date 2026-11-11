#include<fstream>
#include<cmath>
using namespace std;
int  main(){
    ifstream fin("and.in");
    ofstream fout("and.out");
    int n,m;
    fin>>n>>m;
    long long num[n],lans=0;
    for(int i=0;i<n;i++) fin>>num[i];
    bool ejz[n][30],cc[n],ans[30];
    for(int i=0;i<n;i++) cc[i]=ans[i]=1;
    for(int i=0;i<n;i++) for(int j=0;j<30;j++) ejz[i][j]=0;
    for(int i=0;i<n;i++) {
        for(int j=0;num[i]!=0;j++) {
            ejz[i][j]=num[i]%2;
            num[i]/=2;
        }
    }
    for(int j=29;j>0;j--){
        int temp=0;
        for(int i=0;i<n;i++) if(ejz[i][j]&&cc[i]) temp++;
        if(temp>=m){
            for(int i=0;i<n;i++) if(!ejz[i][j]) cc[i]=0;
            if(temp==m){
                for(int i=0;i<n;i++) {
                    if(cc[i]) {
                        for(int k=0;k<30;k++){
                            if(ans[k]==1&&ans[k]==ejz[i][k]) ans[k]=1;
                            else ans[k]=0;
                        }
                    }
                }
                for(int i=0;i<30;i++) if(ans[i]) lans+=pow(2,i);
                fout<<lans;
                return 0;
            }
        }
    }
    for(int i=0;i<n;i++) {
       if(cc[i]) {
            for(int k=0;k<30;k++){
                if(ans[k]==1&&ans[k]==ejz[i][k]) ans[k]=1;
                else ans[k]=0;
            }
        }
    }
    for(int i=0;i<30;i++) if(ans[i]) lans+=pow(2,i);
    fout<<lans;
    return 0;
}
