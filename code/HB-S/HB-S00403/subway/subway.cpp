#include<bits/stdc++.h>
using namespace std;
int w[100][100];
int t[100][100];
int a[100][100];
int k;
int b[1000];
int s[1000];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<k*n;k++){
            cin>>w[i][j];
            b[i]+=w[i][j];
        }
    }
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
    }
    for(int i=0;i<q;i++){
        cout<<b[i];
    }
    return 0;
}
