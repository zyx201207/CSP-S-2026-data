#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int p[30]={1};
bool b[200050][30],r[200050];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=29;i++){
		p[i]=p[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=29;j>=0;j--){
			if(x>=p[j]){
				b[i][j]=1;
				x-=p[j];
			}
		}
	}
	for(int j=29;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(b[i][j]==1&&!r[i])cnt++; 
		}
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(b[i][j]==0)r[i]=1; 
			}
			ans+=p[j];
		}
	}
	cout<<ans;
	return 0;
}
