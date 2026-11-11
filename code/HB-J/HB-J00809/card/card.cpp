#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
set<int>b;
int main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
			b.push(a[i]);
		for(int j=i+1;j<=n;j++){
			if(a[j]==b.found())
			b.pop();
			b.push(a[j]);
		}
	}
	
	return 0;
}
