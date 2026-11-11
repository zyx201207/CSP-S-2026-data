#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200050];
int d[20050][20050];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,ma=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    if(m==1){
        cout<<ma;
    }else if(m==n){
        int aa=a[1];
        for(int i=1;i<=n;i++){
            aa&=a[i];
        }cout<<aa;
    }
	else{
        for(int j=1;j<=m;j++){
            for(int i=1;i<=n;i++){
                int anma=0;
                for(int k=1;k<i;k++){
                    anma=max(int(a[k]&a[i]),anma);
                }d[i][j]=max(int(d[i-1][j]),anma);
                
            }
        }cout<<d[n][m];
        
    }
	return 0;
}
