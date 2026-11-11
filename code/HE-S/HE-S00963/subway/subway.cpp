#include <bits/stdc++.h>
using namespace std;
struct qwe{
	int a;
	int t;	
}s[501];
int c;
int n;
int m;
int d;
int q;
int w[501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	cin>>n;
	cin>>m;
	cin>>d;
	cin>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>s[j].a;
			cin>>s[j].t;
		}
	}
	for(int r=1;r<=q;r++){
		int x;
		int y;
		cin>>x;
		cin>>y;
		int i=1;
		int nx=0;
		int ny=0;
		while(!i++>=3){
			nx+=w[i];
		}
		i=0;
		while(!i++>3){
			ny+=s[i].t;
		}
		cout<<min(nx,ny);
	}
	return 0;
}
