#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int x[35],y[35],z[35],k=0;
int prime(int cc){
	int num=1;
	if(cc==0) return 1;
	for(int i=1;i<=cc;i++)
	    num*=2;
	return num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	    scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=m-1;i++){
		int sum=0,ans=0;
		for(int j=a[n-i+1];j>0;j/=2){
			x[sum]=j%2;
			sum++;
		}
		for(int j=a[n-i];j>0;j/=2){
			y[ans]=j%2;
			ans++;
		}
		int maxn=max(sum,ans);
		for(int j=maxn-1;j>=0;j--){
			if(x[j]==1&&y[j]==1)
			    z[j]=1;
			else
			    z[j]=0;
		}
		for(int j=0;j<maxn;j++)
		    k+=prime(j)*z[j];
		a[n-i]=k;
		k=0;
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
	}
	printf("%d",a[n-m+1]);
	return 0;
}
