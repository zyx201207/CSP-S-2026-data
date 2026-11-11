#include<bits/stdc++.h>
using namespace std;
int n,m,a[300010],l=0;
int gm[300010],s[500010],cnt[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int y=0;y<n;y++) cin>>a[y];
	for(int i=0;i<n;i++){
		for(int y=i;y<n;y++){
			gm[a[y]-1]++,s[l]=a[y],l++;
			if(gm[a[y]-1]>1){
				gm[a[y]-1]=1,s[l]=0,--l;
				while(s[l]!=a[y]) s[l]=0,--l;
				--l,s[l]=0;
			}
		} 
		for(int o=0;o<m;o++){
			if(gm[o]==1) cnt[o]++;
		}
		for(int u=0;u<n+2;u++) gm[u]=s[u]=0;
		l=0;
	}
	for(int y=0;y<m;y++) cout<<cnt[y]<<" ";
	return 0;
}

