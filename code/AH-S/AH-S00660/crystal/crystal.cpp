#include<bits/stdc++.h>
using namespace std;

int n,m,s,a[500001];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	int i;
	for(i=2;i<=n;i++){
		s+=(a[i]-a[i-1])*(i-1);
		if(s>m)break;
		}
	printf("%d",i-1);
	
	return 0;
}
