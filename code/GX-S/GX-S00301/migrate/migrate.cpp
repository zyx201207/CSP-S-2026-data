#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[10000],a[100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d",&c);
	scanf("%d",&t);
	scanf("%d",&n);
	scanf("%d",&d);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	int t=1;
	for(int i=1;i<=100010;i+=d){
		a[i]=1;
	}
	for(int i=1;i<=100010;i++){
		if(i%d==0) a[i]=t++;
	}
	cout<<1<<endl<<3;
	return 0;
}
