#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
int check(int x){
	int l,r,c[500005],e[500005][2],d[500005];
	for(int i=x;i<=n;i++){
		if(c[a[i]]==1){
			for(int j=e[a[i]][2];j<i;j++){
				e[j][1]=0;
			} 
		}else{
			c[a[i]]=1;
			e[e][1]=a[i];
			e[a[i]][2]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(d[e[i][1]]==0){
			b[e[i][1]]++;
			d[e[i][1]]=1;
		}
	}
	return 0;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		check(i);
	}
	return 0;
}
