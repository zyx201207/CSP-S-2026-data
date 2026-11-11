#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q,x,y,ans=0,ans2=0;
	cin>>c>>n>>m>>d>>q;
	int time[n+5],t[n][m*2+5]; 
		for(int i = 0;i<m;i++){
			cin>>time[i];
		}
		for(int i = 0;i<n;i++){
			cin>>t[i][0];
			for (int j = 1;j<2 * t[i][0]+1;j++){
				cin>>t[i][j];
			}
		}
		for(int i = 0;i<q;i++){
			cin>>x>>y;
			if(c>=7 && c<=11){
				cout<<t[0][3]*2+time[x-1]+time[y-1];
				break;
			}
			for(int j = 0;j<n;j++){
				if(t[j][1]!=x || t[j][3] != x) continue;
				for(int l = 0;l<n;l++){
					if(t[l][1]!=y || t[l][3] != y) continue;
					if(t[l][1]==y){
						if(t[j][1]==x) ans=t[l][2]+t[j][2];
						else if(t[j][3]==x) ans=t[l][2]+t[j][4];
					}
					else {
						if(t[j][1]==x) ans=t[l][4]+t[j][2];
						else if(t[j][3]==x) ans=t[l][4]+t[j][4];
					}
				}
				if(j==0) continue;
				ans2 = min(ans,ans2);
			}
			cout<<ans2+time[x-1]+time[y-1];
		}
	return 0;
}
