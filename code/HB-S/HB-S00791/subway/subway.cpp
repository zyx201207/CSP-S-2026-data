#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int MAXM=1e4+5,MAXN=500;
ll c,n,m,d,q;
ll w[MAXM];
int a[MAXM][MAXM]; 
void add(ll u,ll v,int w){
    if(a[u][v]>=w)a[u][v]=w;
    if(a[v][u]>=w)a[v][u]=w;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++){
			if(i!=j)a[i][j]=1e7;
			else a[i][j]=0;
		}
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        int sub1[MAXN],sub2[MAXN];
        cin>>k;
        for(int i=1;i<=k;i++){
            int asd,tim;
            cin>>asd>>tim;
            sub1[i]=asd,sub2[i]=tim;
        }for(int i=1;i<=k;i++){
            for(int j=i;j<=k;j++){
                add(sub1[i],sub1[j],sub2[i]+sub2[j]);
            }
        }
    }
    /*
    for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j]<<" ";
		}cout<<endl;
	}
    */
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=i+1;j<=m;j++){
                a[i][j]=a[j][i]=min(a[i][k]+a[k][j],a[i][j]);
            }
        }
    }
    /*
    for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j]<<" ";
		}cout<<endl;
	}
    */
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+a[x][y]+w[y]<<endl;
    }
    return 0;
}
/*
T2 44pts
1~11
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
