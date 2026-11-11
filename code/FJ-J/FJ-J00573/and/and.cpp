#include<bits/stdc++.h>
using namespace std;
int n,m,x,b[200005];
bool a[200005][35];
int f[200005],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		maxx=max(maxx,x);
	}
	if(m==1){
		cout<<maxx;
	}
	if(m==2){
		int c[100005];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<max(f[i],f[j]);k++){
					if(a[i][k]&&a[j][k]){
						c[k]=1;
					}
				}
			}
		}
		int q=0;
		for(int i=0;i<35;i++){
			q+=pow(2,i)*c[i];
		}
		cout<<q;
	}
	return 0;
}
