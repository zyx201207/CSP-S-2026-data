#include <bits/stdc++.h>
using namespace std;
const int mxn=210,mxm=410;
int w[mxm],a[mxm][mxm];
int c[mxm],t[mxm],ll;
struct node2{
    int len,lx[25];
}b[mxm];
int cc,n,m,d,q,l,r;
void pp(){
    for(int i=1;i<=m;i++,cout<<'\n')
        for(int j=1;j<=m;j++)
            cout<<setw(5)<<a[i][j];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cc>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=m;a[i][i]=0,i++)
        for(int j=1;j<=m;j++)
            a[i][j]=9999;
    for(int i=1;i<=n;i++){
        cin>>ll;
        for(int j=1;j<=ll;j++){
            cin>>c[j]>>t[j];
        }
        for(int j=1;j<=ll;j++)
            for(int k=1;k<=ll;k++){
                int x1=c[j],x2=c[k];
                a[x1][x2]=min(a[x1][x2],t[k]+t[j]);
            }
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=m;k++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
//    cout<<'\n';
//    pp();
    while(q--){
        cin>>l>>r;
        cout<<a[l][r]+w[r]+w[l]<<'\n';
    }
	return 0;
}
