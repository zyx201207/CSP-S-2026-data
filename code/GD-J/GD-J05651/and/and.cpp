#include<bits/stdc++.h>
using namespace std;
int n,m,a[200002][33];
bool x[200002],y[200002],zz[33];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t,z=31;
		cin>>t;
		while(t!=0){
			a[i][z]=t%2;
			t/=2;
			z--;
		}
	}
	for(int z=1;z<=31;z++){
		int h=0;//Îª1µÄ
		for(int i=1;i<=n;i++){
			if(x[i]==0 and a[i][z]==1){
				y[i]=0;
				h++;
			}
			else y[i]=1;
		}
		if(h>=m){
			zz[z]=1;
			for(int j=1;j<=n;j++){
				x[j]=y[j];
			}
		}
	}
	int tt=1,ans=0;
	for(int i=31;i>=1;i--){
		if(zz[i]==1)ans+=tt;
		tt*=2;
	}
	cout<<ans;
	return 0;
} 
