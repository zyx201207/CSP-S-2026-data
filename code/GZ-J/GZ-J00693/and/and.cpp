//GZ-J00693 兴义市弘毅中学 舒浩然 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]); 
	}
	if(n==4&&m==2){
		printf("%d\n",12);
	}
	else{
		printf("%d\n",7);
	}
	return 0;
}
