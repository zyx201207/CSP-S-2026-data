#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],c[200005],ans=0;
bool b[200005];
void f(int k){
	if(k==0){
		int p=c[1];
		for(int i=2;i<=m;i++){
			p=p&c[i];
		}
		ans=max(ans,p);
	}
	for(int i=1;i<=n;i++){
		if(b[i]==false){
			b[i]=true;
			c[k]=a[i];
			f(k-1);
			b[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	f(m);
	printf("%d",ans);
	return 0;
}
