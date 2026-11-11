#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],vs[200005],ans;
bool b[31][200005];
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<30;j++){
			b[j][i]=(a[i]>>j)&1;
		}
	}
	for(int i=29;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vs[j]) continue;
			cnt+=b[i][j];
		}
		if(cnt>=m){
			ans|=(1<<i);
			for(int j=1;j<=n;j++){
				if(!b[i][j]) vs[j]=1;
			}
		} 
	}
	cout<<ans;
	return 0;
}
