#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6+6;
int c,t,n,d;
int x[MAXN];
bool db[MAXN],cd[MAXN],ud[MAXN];
bool doub(int s){//仅用于判断间隔两个岛屿的岛屿对的双径性 
	if(x[s+2]-x[s]<=d&&x[s+3]-x[s+1]<=d&&x[s+3]-x[s]>d){
		return true;
	}
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		memset(db,0,sizeof(db));
		memset(cd,0,sizeof(cd));
		long long ans=0;
		cin >> n >> d;
		for(int j=1;j<=n;j++){
			cin >> x[j];
		}
		for(int j=1;j<=n-3;j++){
			if(doub(j)){
				//形成基本双径性联通桥 
				db[j]=1;
			}
			if(x[j+1]-x[j]>d){
				//断点 
				cd[j]=1;
			}
		}
		long long l=1,r=1;
		memset(ud,0,sizeof(ud));
		for(int j=1;j<=n-3;j++){
			l=1;
			r=1;
			if(db[j]==1){
				int cc=-1;
				ud[j]=1;
				for(int k=j-1;k>=1;k--){
					if(cd[k]==1)break;
					if(x[j]-x[k]<=d&&x[j+1]-x[k]>d){
						cc=j;
						l++;
						ud[j]=1;
						break;
					}
					else break;
				}
				if(cc!=-1){
					int cc1=j;
					for(int k=cc-1;k>=1;k--){
						if(x[cc]-x[k]<=d&&x[cc1]-x[k]>d){
							l++;
						}
						else break;
						cc1=cc;
						cc=k;
					}
				}
				cc=-1;
				for(int k=j+4;k<=n;k++){
					if(x[j]-x[k]<=d&&x[j+1]-x[k]>d){
						cc=j;
						r++;
						ud[j]=1;
						break;
					}
					else break;
					if(cd[k]==1)break;
				}
				if(cc!=-1){
					int cc1=j;
					for(int k=cc+1;k<=n;k++){
						if(x[k]-x[cc]<=d&&x[k]-x[cc1]>d){
							r++;
						}
						else break;
						cc1=cc;
						cc=k;
					}
				}
				ans+=l*r;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
