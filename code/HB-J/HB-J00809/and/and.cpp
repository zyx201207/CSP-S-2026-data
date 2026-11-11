#include<bits/stdc++.h>
using namespace std;
int x,n,m,a[20005];
int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
	printf("%d",a[*max_element(a+1,a+1+n)]);
	return 0;
}
	x=a[1]&a[2];
	for(int i=3;i<=n;i++){
		x=x&a[i];
	}
	cout<<x;
	return 0;
}
