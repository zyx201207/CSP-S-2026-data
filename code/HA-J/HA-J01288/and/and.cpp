#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,a[200050],b[250005],c[200005][35],ans;
bool vis[220005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x=0;
		cin>>x;
		int cnt=0;
		while(x){
			++cnt;
			a[cnt]+=x%2;
			c[i][cnt]=x%2;
			x/=2;
		}
//		for(int k=1;k<=6;k++) cout<<c[i][k];
//		cout<<endl;
		b[i]=cnt;
	}
	int x=0;
	for(int i=31;i>=1;i--){
		if(a[i]>=m){
			x=i;
			break;
		}
	}
	if(x==0){
		cout<<0;
		return 0;
	}
	while(x){
		if(a[x]<m){
			x--;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(c[i][x]==0&&!vis[i]){
				for(int j=1;j<=31;j++){
					a[j]-=c[i][j];
				}
				vis[i]=1;
			}
		}
//		for(int k=1;k<=31;k++) cout<<a[k];
//		cout<<endl;
		x--;
	}
	for(int i=1;i<=31;i++){
		if(a[i]>=m)ans+=pow(2,i-1);
//		cout<<a[i];
	}
	cout<<ans;
	return 0;
}
/*
 
11111
11
1
1111
111
33322


Yk376hJd

*/
