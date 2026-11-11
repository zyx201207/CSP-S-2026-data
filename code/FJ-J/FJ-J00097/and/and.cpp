#include<bits/stdc++.h>
using namespace std;
long long n,m,t,ans,w;
bool a[200005][35];
int p[200005],q[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w;
		for(int j=30;w>0;j--){
			a[i][j]=w&1;
			w>>=1;
		}
		p[i]=i;
	}
	int x=n;
	for(int i=0;i<=30;i++){
		int y=0;
		ans*=2;
		for(int j=1;j<=x;j++){
			if(a[p[j]][i]){
				y++;
				q[y]=p[j];
			}
		}
		if(y>=m){
			for(int j=1;j<=y;j++) p[j]=q[j];
			ans++;
			x=y;
		}
		
	}
	cout<<ans;
}
