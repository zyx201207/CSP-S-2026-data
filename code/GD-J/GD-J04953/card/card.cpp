#include<bits/stdc++.h>
using namespace std;
int n,m,a[101010],b[101010],x=0;
vector<int>c;
bool f(int y){
	for(int k=0;k<c.size();k++){
		if(c[k]==y){
			x=k;
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f(a[j]))for(int k=x;k<c.size();k++)c[k]=0;
			c.push_back(a[j]);
		}
		for(int j=0;j<c.size();j++){
			b[c[j]]++;
		}
		for(int k=0;k<c.size();k++)c[k]=0;
	}
	for(int i=1;i<=m;i++){
		printf("%d ",b[i]);
	}
	return 0;
} 
