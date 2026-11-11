#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
using namespace std;
int c,n,m,d,q,w[500005],a[500005],t[50005],s[22505][22505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            if(i!=j)
                s[i][j]=87654321;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
            cin>>a[j]>>t[j];
        for(int j=1;j<=k;j++)
            for(int l=j+1;l<=k;l++)
                s[a[j]][a[l]]=s[a[l]][a[j]]=t[j]+t[l];
    }
    for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++)
            for(int k=1;k<=m;k++)
                if(k!=i&&k!=j){
                    s[i][j]=min(s[i][k]+s[k][j],s[i][j]);
                    s[j][i]=s[i][j];
            }
    while(q--){
        int a1,b1;
        cin>>a1>>b1;
        if(a1==b1){
            cout<<0;
            continue;
        }
        cout<<w[a1]+w[b1]+s[a1][b1]<<endl;
    }
    return 0;
}
