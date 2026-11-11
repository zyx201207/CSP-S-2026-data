#include<bits/stdc++.h>
using namespace std;
int a[202020];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=-1,ptans,ans=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		maxn=max(maxn,a[i]);
		if(i) ptans&=a[i];
		else ptans=a[i];
	}
	if(m==1){
		printf("%d",maxn);
		return 0;
	}
	if(m==n){
		printf("%d",ptans);
		return 0;
	}
	//vector<int> v;
	for(int b=(1<<30),c=(1<<30);b>0;b>>=1,c|=b){
		int cnt=0;
		for(int i=0;i<n;i++){
			//printf("%d ",a[i]&c);
			if(((a[i]&c)&ans)==ans&&(a[i]&b)) cnt++;
		}
		//putchar('\n');
		if(cnt>=m) ans|=b;
	}
	printf("%d",ans);
	return 0;
}
/*
4 3
3 15 12 12
*/
