#include <iostream>
using namespace std;
int n,m,d,p;
int a[50000][10];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    cin>>n>>m>>d>>p;
    for (int i=0;i<m;i++){
        for (int j=0;j<m;j++){
            cin>>a[i][j];
        }

    }

    return 0;
}
