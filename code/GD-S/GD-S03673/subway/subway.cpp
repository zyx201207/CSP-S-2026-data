#include<bits/stdc++.h>
using namespace std;
const int MXX=1E5+5;
int x[MXX],y[MXX],v[MXX],k[501],a[501][MXX],t[501][MXX],s[MXX],st[501],mxd;
bool trapped=false,fin=false;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,r,go,end;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(r=1;r<=q;r++){
		cin>>x[r]>>y[r];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			st[a[i][j]]++;
			mxd=max(st[a[i][j]],d); 
		}
	}
	for(r=1;r<=q;r++){
		go=x[r];
		end=y[r];
		int tra=0,ex=0,ey=0;
		s[r]+=v[x[r]]+v[y[r]];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==end){
					ex=i,ey=j;
				} 
			}
		}
		if(mxd>d){
			return 0;
		}
		if(go!=end){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=k[i];j++){
					if(trapped){
						if(a[i][j]==tra){
							trapped=false;
							s[r]+=t[i][j];
						}else{
							continue;
						}
					}
					if(a[i][j]==go){
						s[r]+=t[i][j];
					}
					if(st[a[i][j]]>1&&ex==i+1){
						s[r]+=t[i][j];
						trapped=true;
						tra=a[i][j];
					}
					if(st[a[i][j]]==end){
						s[r]+=t[i][j];
						fin=true;
						break;
					}
				}
				if(fin)break;
			}
		}else{
			return 0;
		}
		cout<<s[r]<<endl;
		fin=false;
	}
	return 0;
}
