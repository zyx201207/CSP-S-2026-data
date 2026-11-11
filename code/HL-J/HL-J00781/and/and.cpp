#include <bits/stdc++.h>
using namespace std;
int d[31]={1},e[32][200005],e1[32],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=30;i++){
		d[i]=d[i-1]*2;
	}
	int n,m,ans=0;scanf("%d %d",&n,&m);
	for(int j=0;j<n;j++){
		int x;scanf("%d",&x);
		int t=x,temp,f=0;
		for(int i=30;i>=0;i--){
			if(d[i]<=t){
				if(!f) temp=d[i],f=1;
				t-=d[i];
				e1[i]++;
				e[i][j]=1;
			}
		}
	}
	int t;
	for(int i=30;i>=0;i--){
		if(e1[i]>=m) {
			t=i;
			break;
		} 
	}
	ans+=d[t];
	vector<int>z;
	for(int i=0;i<n;i++){
		if(e[t][i]==1) z.push_back(i);
	}t--;
	for(;t>=0;t--){
		int r=0;
		for(auto j:z){
			if(e[t][j]){
				r++;
			}
		}
		if(r>=m) {
			ans+=d[t];
			for(int j=1;j<=z.size()-1;j++){
				if(!e[t][z[j]]){
					z.erase(z.begin()+j);
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
