#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[5009],b[5009][5009],anss,ans[5009][5009];
void dfs(int bb,int wa,int nb,int bg){
	//cout<<nb<<" "<<bb<<endl;
	//cout<<bb<<endl;
	if(bb>b[bg][wa]+1){
		return;
	}
	if(wa==nb){
		ans[bg][wa]++;
		return;
	}
	int l,r,nl;
	l=nb;r=wa;nl=d;
	while(l<r&&nl>=(x[l+1]-x[l])){
		l++;
		nb-=(x[l+1]-x[l]);
		dfs(bb+1,wa,l,bg);
		
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int ttt=1;ttt<=t;ttt++){
		cin>>n>>d;
		anss=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				b[i][j]=0;
				int l,r,nl;
				l=i;r=j;
				while(l<r){
					nl=d;b[i][j]++;//cout<<l<<endl;
					while(l<j&&nl>=(x[l+1]-x[l])){
						nl-=(x[l+1]-x[l]);
						l++;
						
					}
				}
			}
		}
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ans[i][j]=0;
				dfs(0,j,i,i);
				if(ans[i][j]==2){
					anss++;
					//cout<<i<<"j"<<endl;
				}
			}
		}
		cout<<anss<<endl;
	}
} 
