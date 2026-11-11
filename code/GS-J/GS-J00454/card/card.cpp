#include<bits/stdc++.h>
using namespace std;
const int N=5e5+25;
int n,m,a[N],mm[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			mm[a[i]]++;
		}
		mm[a[n]]=n;
		printf("%d %d",mm[1],mm[2]);
	}
	else{
		for(int i=1;i<=n;i++){
			mm[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			printf("%d ",mm[i]);
		}
	}
	return 0;
}
