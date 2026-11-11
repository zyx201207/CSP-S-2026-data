#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,j=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	while(j<=n){
		map<int,int>s,sf;
		int x=0;
		for(int i=j;i<=n;i++){
			if(s[a[i]]==0){
				x++;
				s[a[i]]=x;
				sf[x]=a[i];
			}else{
				for(int w=s[a[i]]+1;w<=x;w++){
					s[sf[w]]=0;
					sf[w]=0;
				} 
				x=s[a[i]];
			}
		}
		for(int i=1;i<=m;i++){
			if(s[i]){
				b[i]++;
			}
		}
		j++;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
} 
