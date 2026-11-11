#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100005],t[1005][1005],c[10005],fl[10005],fla=0;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof c);
		memset(fl,0,sizeof fl);
		for(int j=i;j<=n;j++){
			c[j]=a[j];
			fla=0;
			for(int k=1;k<=j;k++){
				fla+=fl[k];
				if(c[k]==a[j]&&!fla){
					fl[k]++;
					fl[j]--;
					break;
				}
			}
		}
		fla=0;
		for(int j=1;j<=n;j++){
			fla+=fl[j];
			if(!fla){
				t[i][c[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			ans+=t[j][i];
		}
		cout<<ans<<' ';
	}
	return 0;
}
/*
67 83 80 82 80 43 61 73 78 70
*/
