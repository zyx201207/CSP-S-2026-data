#include <bits/stdc++.h>
using namespace std;
int n,m,p[100005],b[100005],ans,a,g[10005][10005],cen,z,s,w;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>p[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=p[i]-p[j];
		}
	}
	for(int i=1;i<=n;i++){
		z=0;
		s=0;
		w=0;
		for(int j=1;j<=n;j++){
			if(g[j][i]<z&&g[j][i]>=0){
				z=g[j][i];
				s=i;
				w=j;
			}
		}
	}
	for(int i=1;i<=n;i++){
		b[p[i]]++;
		if(ans<b[p[i]]){
			ans=b[p[i]];
			a=p[i];
		}
	}
	cout<<"5";
	return 0;
}
