#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],zc=0,zc1=0,o=0,ans;
string zdc="",bjc="",ccc="abcdefghijklmnopqrstuvwxyz";
char cc;
bool bf(string g,int c){
	for (int s=0;s<c;s++){
		if (g[s]!=g[c-s-1]){
			return 0;
		}
	}
	return 1;
}
int sss(string yl,string bj,int cd){
	int z;
	for (int s=0;s<cd;s++){
		if (yl[s]!=bj[s]){
			z++;
		}
	}
	return z;
}
int main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>cc;
		long long z1=zc+a[i];
		for (int j=zc;j<z1;j++){
			zdc[j]=cc;
		}
		zc=z1;
	}
	ans=zc; 
	bjc=zdc;
	for (int y=0;y<zc;y++){
		for (int k=0;k<zc;k++){
			for(int u=0;u<24;u++){
				bjc[y]=ccc[u];
				bjc[k]=ccc[u];
				if (bf(bjc,zc)){
					o=sss(zdc,bjc,zc);
					ans=min(ans,o);
				}
			}
		}
	}
	cout<<ans;
}
