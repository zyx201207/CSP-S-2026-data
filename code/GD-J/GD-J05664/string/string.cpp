#include<bits/stdc++.h>
using namespace std;
#define int long long
struct k{
	int sum;
	char b;
}g[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		g[i].sum=a;
		g[i].b=c;
	}
	int ans=0,i=0,j=n-1,l=0,shen=0;
	while(i!=j){
		if(shen!=0){
			if(l!=0){
				if(shen>l){
					shen-=l;
					ans+=l;
				}else if(shen<l){
					ans+=shen;
					l-=shen;
					shen=0;
				}else{
					ans+=l;
					shen=0;
					l=0;
				}
			}else if(g[i].b!=g[j].b){
				if(shen>=g[j].sum){
					shen-=g[j].sum;
					ans+=g[j].sum;
					j--;
				}else{
					ans+=shen;
					l=g[j].sum-shen;
					shen=0;
					j--;
				}
			}
		}else{
			if(g[i].b!=g[j].b){
				if(g[i].sum>g[j].sum){
					shen=g[i].sum-g[j].sum;
					ans+=g[j].sum;
					j--;
				}else{
					l=g[j].sum-g[i].sum;
					ans+=g[i].sum;
					i++;
				}
			}else{
				if(g[i].sum>g[j].sum){
					shen=g[i].sum-g[j].sum;
					j--;
				}else{
					l=g[j].sum-g[i].sum;
					i++;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

