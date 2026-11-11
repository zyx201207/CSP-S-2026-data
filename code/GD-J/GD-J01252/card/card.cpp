#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int n,m,a[500005], h[300005], w[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
	h[a[i]]=i;
}
for(int i=1;i<=n;i++){
	int id=i;
	while(id<=n){
		id=h[a[id]];
		w[a[id]]++;
		id++;
	}
	
}
for(int i=1;i<=m;i++)printf("%d ",w[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
