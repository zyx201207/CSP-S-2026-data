#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,p,i,j,k,a[50010],b[110],s[110][110],t[110][110],l,r;
	cin>>c>>n>>m>>d>>p;
	for(i=1;i<=m;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		cin>>b[i];
		for(j=1;j<=b[i];j++){
			cin>>s[i][j]>>t[i][j];
		} 
	} 
	for(i=1;i<=p;i++){
		cin>>l>>r;
		int x=0,x1=1;
		int z=0,v;
		z+=a[l]+a[r];
		for(j=1;j<=n;j++){
			for(k=1;k<=b[i];k++){
				if(s[j][k]==r){
					x=1;
					z+=t[j][k];
					cout<<z<<'\n';
					break;
				}
				if(s[j][k]==v){
					x1=1;
				}
				if(x1){
					if(s[j][k]+1==s[j][k+1]){
						z+=t[j][k];
					}else{
						z+=t[j][k];
						v=s[j][k];
						x1=0;
						break;
					}
				}
			}
			if(x){
				break;
			}
		}
		
	}
	return 0;
}
