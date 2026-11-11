#include<iostream>
#include<cstdio>
using namespace std;
int a[200001];
bool v[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0,x,sum;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int j=30;~j;j--){
		x=1<<j;
		sum=0;
		for(int i=1;i<=n;i++) if(!v[i]&&(a[i]&x)) sum++;
		if(sum<m) continue;
		ans|=x;
		for(int i=1;i<=n;i++) if(!(a[i]&x)) v[i]=1;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
