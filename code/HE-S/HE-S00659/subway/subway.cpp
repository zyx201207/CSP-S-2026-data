#include<bits/stdc++.h>
using namespace std;
long long n,m,c,q,d,cnt=INT_MAX;
long long w[50050],k[550],a[550][50050],t[550][50050],f[50050],l[50050],g[50050][550];
void aaa(long long x,long long y,long long cc){
	if(x==y){
		//cout<<" a "<<cc<<endl;
		cnt=min(cnt,cc);
		return;
	}
	//for(int i=1;i<=n;i++){
		for(int j=1;j<=l[x];j++){
			for(int o=1;o<=k[ g[x][j] ];o++){
				if(f[ a[ g[x][j] ][ o ] ] == 0){
					f[ a[ g[x][j] ][ o ] ]=1;
					//cout<<"起点:"<<x<<" 站点:"<<a[ g[x][j] ][ o ]<<" 线路:"<<g[x][j]<<endl;
					cc=cc+t[g[x][j]][o]+t[g[x][j]][x];
					//cout<<"cc:"<<cc<<"增加:"<<t[g[x][j]][o]<<" + "<<t[g[x][j]][x]<<endl;
					aaa(a[ g[x][j] ][ o ],y,cc);
					cc-=t[g[x][j]][o]+t[g[x][j]][x];
					f[ a[ g[x][j] ][ o ] ]=0;
				}
			}
		}
	//}
	return;
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		l[i]=1,f[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			g[ a[i][j] ][ l[ a[i][j] ] ] = i;
			l[ a[i][j] ]++;
		}
		
	}
	long long r1,l1;
	for(int i=1;i<=q;i++){
		cin>>l1>>r1;
		cnt=INT_MAX;
		f[l1]=1;
		aaa(l1,r1,0);
		cnt=cnt+w[l1]+w[r1];
		cout<<cnt;
	}
	return 0;
} 
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
