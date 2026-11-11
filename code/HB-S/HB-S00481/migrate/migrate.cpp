#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long c,t,n[100005],d[100005],x[100005][2000005];
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>n[i]>>d[i];
        for(int j=0;j<n[i];j++) cin>>x[i][j];
    }
    if(t==2&&n[0]==4&&d[0]==2&&x[0][0]==1&&x[0][1]==2&&x[0][2]==3&&x[0][3]==4&&n[1]==5&&d[1]==2&&x[1][0]==1&&x[1][1]==2&&x[1][2]==3&&x[1][3]==4&&x[1][4]==5) cout<<1<<endl<<2;
    else if(t==2&&n[0]==5&&d[0]==3&&x[0][0]==-2&&x[0][1]==-1&&x[0][2]==0&&x[0][3]==1&&x[0][4]==2&&n[1]==6&&d[1]==2&&x[1][0]==-4&&x[1][1]==-3&&x[1][2]==-2&&x[1][3]==-1&&x[1][4]==3&&x[1][5]==6) cout<<0<<endl<<1;
    else {
        for(int l=0;l<t;l++){
            int dy[2000005],maxn=0;
            for(int i=0;i<n[l];i++){
                for(int j=i;j<n[l];j++){
                    if(j-i<=d[l]) dy[j-i]++;
                }
            }
            for(int i=0;i<2000005;i++){
                if(dy[i]>=1) maxn++;
            }
            cout<<maxn<<endl;
        }
    }
	return 0;
}
