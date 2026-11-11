#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q,w[1000005],k[500005],p[500005],f[500005][2],flag,ans=0x3f3f3f3f,x,y;
vector<int> a[505],s[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        int h=0;
        for(int j=1;j<=k[i];j++){
            cin>>h;
            a[i].push_back(j);
            p[h]++;
        }
    }
    while(q--){
        cin>>x>>y;
        int f1=0,f2=0,f3=0,f4=0;
        for(int i=1;i<a[i].size();i++){
            if(a[1][i]==x) f1=1;
            if(a[1][i]==y) f2=1;
            if(a[2][i]==x) f3=1;
            if(a[2][i]==y) f4=1;
            if(p[a[1][i]]==2) ans=min(ans,min(a[1][i],a[2][i]));
        }
        if(f1==1&&f2==1 || f3==1&&f4==1){
            cout<<w[1]+w[n]<<endl;
        }else cout<<ans+w[1]+w[n]<<endl;
    }
    return 0;
}
