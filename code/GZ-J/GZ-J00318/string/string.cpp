//GZ-J00318 贵阳中天中学 吴竣驰 
#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
int n,x,k=0,ans=0,w;
char r,p[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>r;
		k+=x;
		for(int j=1;j<=x;j++){
			w++;
			p[w]=r;
		}
	}
	
	for(int i=1;i<=k/2+1;i++){
		if(p[i]!=p[k+1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
