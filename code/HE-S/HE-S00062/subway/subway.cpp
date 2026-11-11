#include <bits/stdc++.h>
using namespace std;
const int N=510;
const int M=5e5+10;
int c,n,m,d,q;
int w[M];
int t[N][N];
int a[N][N];
int k[N];
int check(int st,int ed){
    int tm=0;
    int idx;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            if(a[i][j]==st){
                idx=i;
                tm+=w[a[i][j]];
                tm+=t[i][a[i][j]];
            }
        }
    }
    for(int i=1;i<=k[idx];i++){
        if(a[idx][i]==ed){
            tm+=t[idx][ed];
            tm+=w[ed];
        } else{
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                for(int l=1;l<=k[j];l++){
                    if(a[j][l]==a[idx][i]){
                    	tm+=t[idx][a[idx][i]]+t[j][a[j][l]];
                        for(int o=1;o<=k[j];o++){
                            if(a[j][o]==ed){
                                tm+=t[j][ed]+w[ed];
                            }
                        }
                    }
                }
            }
        }
    }
    return tm;
}
int main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
        cin>>w[i];
	}
	for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
            cin>>t[i][a[i][j]];
        }
	}
	while(q--){
        int x,y;
        cin>>x>>y;
        cout<<check(x,y)<<endl;
	}
	return 0;
}
