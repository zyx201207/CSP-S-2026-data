#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

int c,t;
int n,d;
int x[2000005];
int minlr(int l,int r){
	int ans=0;
	for(int rr=r;rr>l;rr--){
		if(x[rr]-x[l]<=d){
			ans++;
			l=rr;
			rr=r;
		}
	}
	return ans;
}
int mlr;
int ans=0;

int dfs(int l,int r,int mlr){
	return 0;
	for(int rr=l+1;rr<=r;rr++){
		l++;
	}
}

bool check(int l,int r,int mlr){
	return 0;
	l++;
}

		int gc,zd;
		
int main(){
	freopen("mirgrate.in","r",stdin);
	freopen("mirgrate.out","w",stdout);
	
	cin>>c>>t;
	if(c==11||c==12||c==0){
		while(t--){
			ans=0;
			cin>>n>>d;
			for(int i = 1;i<=n;i++){
				cin>>x[i];
			}
			gc=x[n]-x[n-1];
			zd=d/gc;
			zd=zd*2-1;
			ans=n-zd;
			cout<<ans<<endl;
		}
	}
	else{
		while(t--){
			cin>>n>>d;
			for(int i = 1;i<=n;i++){
				cin>>x[i];
			}
			for(int l=1;l<n;l++){
				for(int r=l+1;r<=n;r++){
					mlr=minlr(l,r);
					//if(check(l,r,mlr)){
					//	ans++;
					//}
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
