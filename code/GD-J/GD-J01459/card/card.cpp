#include<bits/stdc++.h>
using namespace std;
int n,m,y;
int a[500005],b[300005];
int desk[500005];
bool pd(int x){
	for(y=0;y<=n;y++){
		if(desk[y]==x){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		desk[500005]={ };
		for(int j=i;j<=n;j++){
			if(pd(a[j])){
				for(int k=y;k<=m;k++){
					desk[k]=0;
				}	
			}
			int fst=0;
			while(desk[fst]!=0){
				fst++;
			}
			desk[fst]=a[j];
		}
		for(int j=i;j<=n;j++){
			b[desk[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
