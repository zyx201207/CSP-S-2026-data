#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[510][500005],t[510][500005],k[500005],x,y,ans;
bool v[510][500005];
int sum=1e7;
int f(int s,int e,int T){
	if(s==e){     
		return T;
	}  
	for(int i=1;i<=n;i++){
		int v1=1;
		for(int j=1;j<=k[i]&&v1;j++){
			if(a[i][j]==s){
				v1=0;
				for(int h=1;h<=k[i];h++){
					if(v[i][h]==0&&a[i][h]!=s){
						v[i][h]=1;
						T+=t[i][h];
						sum=min(sum,f(a[i][h],e,T));
						T-=t[i][h];
						v[i][h]=0;
					}
				}
			} 
		}
	}
	return sum;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin >>w[i];
	}
	for(int i=1;i<=n;i++){
		cin >>k[i];
		for(int j=1;j<=k[i];j++){
			cin >>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		cin >>x>>y;
		if(x==y){
			cout <<0<<endl;
			continue;
		}
		else{
			ans=w[x]+w[y];
			ans+=f(x,y,0);
		}
	}
	cout <<ans;
	return 0;
}
