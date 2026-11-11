#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int w,a,b,q,c;
	cin>>w>>a>>b>>q>>c;
	int n[b];
	for(int i=0;i<b;i++)cin>>n[i];
	int l=a,k,m[3005][100005];
	while(l--){
		cin>>k;
		k*=2;
		for(int i=0;i<k;i++){
			cin>>m[a-l-1][i];
		}
	}
	while(c--){
		int hh,jj,h=0;
		cin>>hh>>jj;
		h+=n[hh-1]+n[jj-1];
		for(int i=0;i<a;i++){
			for(int j=0;j<=k;j+=2){
				if(m[i][j]==hh||m[i][j]==jj)h+=m[i][j+1];
			}
		}
		cout<<h<<endl;
	}
	return 0;
}
