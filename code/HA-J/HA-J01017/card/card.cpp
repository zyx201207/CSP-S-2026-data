#include<bits/stdc++.h>
using namespace std;
int m,n;
int d[100011],o[100011],h=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>m>>n;
	int ans[n+10]={0};
	for(int i=1;i<=m;i++){
		cin>>d[i];
	}
	int l=m;
	while(m!=0){
		int c[100011]={0},z=0;
		for(int i=l-m+1;i<=l;i++){
			int p=0;
			for(int j=1;j<=i;j++){
				z=0;
				if(c[j]==d[i]){
					for(int k=j-1;k<=l;k++){
						c[k]=0;
						z++;
					}
				}
			}
			c[p-z]=d[i];
			o[h]=c[p];
			h++;
			p++;
		}
		m--;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=h;j++){
			if(i==o[j]){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
return 0;
}
