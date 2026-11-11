#include<bits\stdc++.h>
using namespace std;
int n,m,a[200010],res;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(m==1)
		for(int i=1;i<=n;i++)res=max(res,a[i]);
	else if(m==2)
		for(int i=1;i<n;i++)res=max(a[i]&a[i+1],res);
	else if(m==n){
		res=a[1];
		for(int i=2;i<=n;i++)res&=a[i];
	} 
	cout<<res;
	return 0;
}
