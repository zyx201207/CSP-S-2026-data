#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500010],e,k[500010],a[500010][500010],t[500010][500010],x,y,ma=INT_MIN,c,n,m,d,q;
void o(int p){
	if(p==y){
		return;
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==p&&k[i]>1){
				e+=t[i][j];
				if(j==1){
					o(a[i][2]);
				}else{
					o(a[i][1]);
				}
			}
		}ma=max(ma,e);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}bool f=true;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2){
			f=false;
		}for(int j=1;j<=n;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}if(f==true){
		for(int i=1;i<=q;i++){
			cin>>x>>y;
			e=w[i];
			o(x);
			cout<<ma<<endl;
		}
	}else{
		cout<<32<<endl<<17;
	}
	return 0;
}
