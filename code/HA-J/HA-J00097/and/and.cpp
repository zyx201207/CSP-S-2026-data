#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	char a[10005];	
	char s;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	for(int j = 0;j <= n;j++){
		s = max(a[j]&a[j+1]);
}
	printf("%d",s);
	return 0;
}
