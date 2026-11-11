#include<fstream>
using namespace std;
int  main(){
    ifstream fin("card.in");
    ofstream fout("card.out");
    int n,m;
    fin>>n;
    int a[n],b[n],len=0,ans[m];
    for(int i=0;i<n;i++) fin>>a[i];
    for(int i=0;i<m;i++) ans[i]=0;
    for(int i=0;i<n;i++){
            len=0;
        for(int j=i;j<n;j++){
            b[len]=a[j];
            for(int k=0;k<len;k++) if(b[k]==a[j]) len=k+1;
        }
        for(int j=0;j<len;j++) ans[b[j]]++;
    }
    for(int i=0;i<m;i++) fout<<ans[m]<<' ';
    return 0;
}
