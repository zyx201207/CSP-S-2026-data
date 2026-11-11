#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m; cin>>n>>m;
	bool f[200010][32]={false};
	
	for(int i=0;i<n;i++){
		int x,cnt=0; cin>>x;
		while(x!=0){
			cnt++;
			if(x&1)f[i][cnt]=true;
			x>>=1;
		}
	}
	
	bool bit[32]={false},is=true;
	bool vis[200010][32]={false};
	int last=0;
	for(int i=31;i>0;i--){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(f[j][i] && (is||vis[j][last])){
				vis[j][i]=true;
				cnt++;
			}
		}
		if(cnt>=m){
			is=false;
			bit[i]=true;
			last=i;
		}
	}
	long long ans=0;
	for(int i=31;i>0;i--){
		ans=(ans<<1)+(int)bit[i];
	} cout<<ans;
	
	
	return 0;
}
