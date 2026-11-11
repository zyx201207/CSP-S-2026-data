#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[200005];
int sum[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<=30;i++){
		sum[i]=(1<<i);
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0,x=ans+sum[i];
		for(int j=1;j<=n;j++){
			if((a[j]&x)==x)cnt++;
		}
		if(cnt>=m)ans=x;
	}
	printf("%d",ans);
	return 0;
}/*
5 3
31 3 1 15 7
*/
