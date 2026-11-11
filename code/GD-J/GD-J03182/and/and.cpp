#include<bits/stdc++.h>
using namespace std;
long long n,m,p[50],ma;
bool t[200055][35],ans[50];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	p[32]=1;
	for(int i=31;i>=1;i--){
		p[i]=p[i+1]*2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int u,o=32;
		cin>>u;
		while(u!=0){
			int y=u%2;
			t[i][o]=y;
			u/=2;
			o--;
		}
	}
	for(int k=1;k<=32;k++){
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(t[i][0]==0) sum+=t[i][k];
		}
		if(sum>=m){
			for(int i=1;i<=n;i++){
				if(t[i][k]==0) t[i][0]=1;
			}
			ans[k]=1;
		}
	}
	for(int i=1;i<=32;i++){
		ma+=p[i]*ans[i];
	}
	cout<<ma;
	return 0;
}
