#include<bits/stdc++.h>
using namespace std;
int n,m,u,v=INT_MIN,vv;
int a[200005];
int g[200005];
int aa[40];
bool f[40][200005];
void cc(int x,int y){
	u=(x&y);
	return;
}
void bb(){
	u=g[1];
	for(int i=2;i<=m;i++){
		cc(u,g[i]);
	}
	v=max(v,u);
	return; 
}
void aaa(int x,int y){
	if(x==m){
		bb();
		return;
	}
	for(int i=y;i<=n;i++){
		g[x+1]=a[i];
		aaa(x+1,i+1);
		g[x+1]=0;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(n>=2000&&m>3){
			int y=0;
			while(1){
				y++;
				if(a[i]%2==1) f[y][i]=1;
				aa[y]+=a[i]%2;
				a[i]=a[i]/2;
				if(a[i]==0){
					v=max(v,y);
					break;
				}
			}	
		}
		
	}
	if(n>=2000&&m>3){
		int u=1;
		for(int i=1;i<=v;i++){
			if(i!=1) u*=2;
			if(aa[i]>=m) vv+=u;
		}
		cout<<vv;
		return 0;
	}
	aaa(0,1);
	cout<<v;
	
	return 0;
}
