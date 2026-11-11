#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,p;
    cin>>c>>n>>m>>d>>p;
    int x[m];
    for(int i=0;i<m;i++)cin>>x[m];
    int s[n];
    int a[n][100];
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<2*s[i];j++)cin>>a[i][j];
    }
    int b[p][2];
    for(int i=0;i<p;i++)cin>>b[i][0]>>b[i][1];
    return 0;
}
