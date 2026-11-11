#include <bits/stdc++.h>
using namespace std;
const int N=505;
const int M=1005;
int w[M];
int c,n,m,d,q;
int gragh[M][M]; 
int a[N][M];
int t[N][M];
int v[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		int ans1=w[l]+w[r],ans2=w[l]+w[r],mit=INT_MAX/3;
		if(n<=3){
			ans1+=w[l];
			for(int i=1;i<=n;i++){
				int fl=0,fr=0,ti;
				for(int j=1;j<=n;j++){
					if(a[i][j]==l){
						fl=1;
					}
					if(a[i][j]==r){
						fr=1;
						ti=t[i][j];
					}
				}
				if(fl&&fr){
					mit=min(ti,mit);
				}
			}
			ans1+=mit;
			for(int i=1;i<=n;i++){
				int fl=0,fr=0,ti;
				for(int j=1;j<=n;j++){
					if(a[i][j]==l){
						fl=1;
					}
					if(a[i][j]!=r){
						fr=1;
						ti=t[i][j];
					}
				}
				if(fl&&fr){
					mit=min(ti,mit);
				}
			}
			ans2+=mit;
			for(int i=1;i<=n;i++){
				int fl=0,fr=0,ti;
				for(int j=1;j<=n;j++){
					if(a[i][j]!=l){
						fl=1;
					}
					if(a[i][j]==r){
						fr=1;
						ti=t[i][j];
					}
				}
				if(fl&&fr){
					mit=min(ti,mit);
				}
			}
			ans2+=mit;
			cout<<min(ans1,ans2);
		}
	}
	return 0;
} 
/*
或许我已经AFO了吧
S组100分也只有我这个废物能考出来了吧
已经不想骗分了
只想躺在凳子上，吃着脆香米，抓住一些虚无缥缈的东西
17:01
不好意思先生，您这酒店躺着真不舒服
我要开始骗分了 
0 2 3 2 1
1 2 3
3 1 1 2 1 3 3
2 2 1 3 1
1 3
*/
