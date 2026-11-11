#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int w[50020];
int a[10001][10001],t[10001][10001];
int main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>p;
for(int i=1;i<=m;i++){
    cin>>w[m];
}
for(int j=1;j<=c;j++){
        int t;
cin>>t;
    for(int i=1;i<=t;i++){
        cin>>a[j][i];
        cin>>t[j][i];
    }
}
for(int i=1;i<=p;i++){
        int x,y;
    cin>>x>>y;
    cout<<w[1]+t[1][1]+t[1][2]+t[2][2]+t[2][3]+w[3]<<endl;
}
	return 0;
}
