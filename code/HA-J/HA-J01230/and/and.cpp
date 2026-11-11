#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],z=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	do{
		long long l=0;
		for(int i=1;i<=m;i++)
		if(a[i]){
			if(l)l=l&a[i];
		    else l=a[i];
		}else{
			l=0;
			break;
		}
		if(l>z)z=l;
	}while(next_permutation(a+1,a+n+1));
	printf("%lld",z);
	fclose(stdin);fclose(stdout);
	return 0;
}
